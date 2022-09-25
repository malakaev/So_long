/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_info_on_table_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:13:35 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:21:56 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_info_on_tab(t_param *prm, t_map *map)
{
	ft_int_to_char(prm->steps, prm);
	mlx_string_put(prm->mlx, prm->win, 15, DTXT, YELLOW, "Steps:");
	mlx_string_put(prm->mlx, prm->win, 80, DTXT, YELLOW, prm->num_str);
	if (prm->win_width > 350)
	{
		ft_int_to_char(prm->collected, prm);
		mlx_string_put(prm->mlx, prm->win, 210, DTXT, GREEN, "Collected:");
		mlx_string_put(prm->mlx, prm->win, 320, DTXT, GREEN, prm->num_str);
	}
	if (prm->win_width > 440)
	{
		ft_int_to_char(prm->coll_sum, prm);
		mlx_string_put(prm->mlx, prm->win, 310 + map->sprt_size, \
		DTXT, GREEN, " of ");
		mlx_string_put(prm->mlx, prm->win, 310 + map->sprt_size + 40, \
		DTXT, GREEN, prm->num_str);
	}
}

void	ft_table_put(t_param *prm, t_map *map)
{
	int	x;

	x = -1;
	while (++x < prm->win_width)
		mlx_put_image_to_window(prm->mlx, prm->win, map->tab, \
		x * map->sprt_size, 0);
	ft_put_info_on_tab(prm, map);
}

void	ft_table_put2(t_param *prm, t_map *map)
{
	mlx_put_image_to_window(prm->mlx, prm->win, map->tab, 80, 0);
	mlx_put_image_to_window(prm->mlx, prm->win, map->tab, 320, 0);
	ft_int_to_char(prm->steps, prm);
	mlx_string_put(prm->mlx, prm->win, 80, DTXT, YELLOW, prm->num_str);
	if (prm->win_width > 350)
	{
		ft_int_to_char(prm->collected, prm);
		mlx_string_put(prm->mlx, prm->win, 320, DTXT, GREEN, prm->num_str);
	}
}
