/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:48:44 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 15:28:12 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_param *prm, t_map *map, unsigned int i, t_put_img *m)
{
	m->x1 = -1;
	while (++m->x1 < map->columns)
	{
		m->x = m->x1 * map->sprt_size;
		mlx_put_image_to_window(prm->mlx, prm->win, map->bg, m->x, m->y);
		if (map->map[m->y1][m->x1] == 'C')
			mlx_put_image_to_window(prm->mlx, prm->win, map->coll[i % 6], \
			m->x, m->y);
		else if (map->map[m->y1][m->x1] == 'E')
			mlx_put_image_to_window(prm->mlx, prm->win, \
			map->exit[i / 2 % prm->unlock_exit], m->x, m->y);
		else if (map->map[m->y1][m->x1] == '1')
			mlx_put_image_to_window(prm->mlx, prm->win, map->wall, m->x, m->y);
		if (map->pl_drc == RIGHT)
			mlx_put_image_to_window(prm->mlx, prm->win, map->plr[i % 5], \
			map->pos.x * map->sprt_size, map->pos.y * map->sprt_size + DY);
		else
			mlx_put_image_to_window(prm->mlx, prm->win, map->pll[i % 5], \
			map->pos.x * map->sprt_size, map->pos.y * map->sprt_size + DY);
	}
}

void	ft_put_img_map(t_param *prm, t_map *map, unsigned int i)
{
	t_put_img	m;

	m.y1 = -1;
	while (++m.y1 < map->rows)
	{
		m.y = m.y1 * map->sprt_size + DY;
		ft_put_img(prm, map, i, &m);
	}
}
