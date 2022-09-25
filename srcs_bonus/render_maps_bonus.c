/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:18:04 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:43:07 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_render_map(t_param *prm)
{
	static unsigned int	count;
	t_map				*map;

	if (prm->result == STOP)
		return (0);
	prm->count++;
	if (prm->result == WIN || prm->result == LOST)
		ft_game_end(prm);
	map = prm->map;
	if (prm->count % 10 == 0)
	{
		count++;
		ft_patrol_move(map);
	}
	ft_put_img_map(prm, map, count);
	if (map->map[map->pos.y][map->pos.x] == 'Z')
	{
		prm->result = LOST;
		ft_game_end(prm);
	}
	return (0);
}

int	ft_render_map_big(t_param *prm)
{
	static unsigned int	count;
	t_map				*map;

	if (prm->result == STOP)
		return (0);
	prm->count++;
	if (prm->result == WIN || prm->result == LOST)
		ft_game_end(prm);
	map = prm->map;
	if (prm->count % 5 == 0)
	{
		count++;
		ft_patrol_move(map);
	}
	ft_put_img_bigmap(prm, map, count);
	if (map->map[map->pos.y][map->pos.x] == 'Z')
	{
		prm->result = LOST;
		ft_game_end(prm);
	}
	return (0);
}
