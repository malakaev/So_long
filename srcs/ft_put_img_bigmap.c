/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img_bigmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:59:34 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 15:24:59 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_put_img	ft_put_big(t_param *prm, t_map *map, unsigned int i, t_put_img m)
{
	while ((++m.x1 - m.ddx) * map->sprt_size <= \
	(map->pos.x + m.ddx) * map->sprt_size && m.x1 < map->columns)
	{
		m.x = (m.x1 - map->pos.x + m.ddx) * map->sprt_size;
		mlx_put_image_to_window(prm->mlx, prm->win, map->bg, m.x, m.y);
		if (map->map[m.y1][m.x1] == 'C')
			mlx_put_image_to_window(prm->mlx, prm->win, \
			map->coll[i % 6], m.x, m.y);
		else if (map->map[m.y1][m.x1] == 'E')
			mlx_put_image_to_window(prm->mlx, prm->win, \
			map->exit[i / 2 % prm->unlock_exit], m.x, m.y);
		else if (map->map[m.y1][m.x1] == '1')
			mlx_put_image_to_window(prm->mlx, prm->win, map->wall, m.x, m.y);
		if (map->pl_drc == RIGHT)
			mlx_put_image_to_window(prm->mlx, prm->win, \
			map->plr[i % 5], PLX, PLY);
		else
			mlx_put_image_to_window(prm->mlx, prm->win, \
			map->pll[i % 5], PLX, PLY);
	}
	return (m);
}

void	ft_put_img_bigmap(t_param *prm, t_map *map, unsigned int i)
{
	t_put_img	m;

	m.ddx = PLX / map->sprt_size;
	m.ddy = (PLY - DY) / map->sprt_size;
	m.y1 = map->pos.y - m.ddy - 1;
	if (m.y1 < 0)
		m.y1 = -1;
	mlx_clear_window(prm->mlx, prm->win);
	while ((++m.y1 - m.ddy) * map->sprt_size + DY < (map->pos.y + m.ddy) \
	* map->sprt_size && m.y1 < map->rows)
	{
		m.y = (m.y1 - map->pos.y + m.ddy) * map->sprt_size + DY;
		m.x1 = map->pos.x - m.ddx - 1;
		if (m.x1 < 0)
			m.x1 = -1;
		m = ft_put_big(prm, map, i, m);
	}
}
