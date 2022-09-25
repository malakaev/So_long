/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_end_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:08:57 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:21:56 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_game_end(t_param *prm)
{
	if (prm->result == WIN)
	{
		printf("YOU WIN!!!\n");
		mlx_clear_window(prm->mlx, prm->win);
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 - 80, \
		prm->win_height / 2 - 30, YELLOW, "Yeeee! YOU WIN!!!");
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 - 90, \
		prm->win_height / 2, YELLOW, "YOUR TOTAL STEPS:");
		ft_int_to_char(prm->steps, prm);
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 + 90, \
		prm->win_height / 2, YELLOW, prm->num_str);
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 - 100, \
		prm->win_height / 2 + 31, GREEN, "YOU HAVE COLLECTED:");
		ft_int_to_char(prm->collected, prm);
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 + 100, \
		prm->win_height / 2 + 31, GREEN, prm->num_str);
	}
	else
	{
		printf("SORRY, BRO, BUT YOU LOST.\n");
		mlx_clear_window(prm->mlx, prm->win);
		mlx_string_put(prm->mlx, prm->win, prm->win_width / 2 - 120, \
		prm->win_height / 2, RED, "SORRY, BRO, BUT YOU LOST.");
	}
	prm->result = STOP;
}
