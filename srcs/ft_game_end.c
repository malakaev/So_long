/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:08:57 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 15:08:23 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	prm->result = STOP;
}
