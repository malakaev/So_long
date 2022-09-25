/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:32:21 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 15:01:17 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_img(t_param *prm)
{
	int	i;

	mlx_destroy_image(prm->mlx, prm->map->wall);
	mlx_destroy_image(prm->mlx, prm->map->tab);
	mlx_destroy_image(prm->mlx, prm->map->bg);
	i = -1;
	while (++i < 6)
	{
		mlx_destroy_image(prm->mlx, prm->map->coll[i % 6]);
		mlx_destroy_image(prm->mlx, prm->map->exit[i % 6]);
	}
	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(prm->mlx, prm->map->plr[i % 5]);
		mlx_destroy_image(prm->mlx, prm->map->pll[i % 5]);
	}
}

void	ft_err_exit(int code, char *str)
{
	write(1, "Error\n", 6);
	printf("Code %d: %s\n", code, str);
	exit(EXIT_FAILURE);
}

int	ft_win_closed(int code)
{
	printf("Exitcode: %d Window closed by pressed x\n", code);
	exit (EXIT_SUCCESS);
	return (0);
}

int	ft_exit(int code, t_param *prm)
{
	if (code == WIN)
	{
		printf("YOU WIN!\n");
		exit (EXIT_SUCCESS);
	}
	if (code == EXIT)
	{
		ft_clear_img(prm);
		mlx_destroy_window(prm->mlx, prm->win);
		printf("Exited by pressed ESC\n");
		exit (EXIT_SUCCESS);
	}
	return (0);
}
