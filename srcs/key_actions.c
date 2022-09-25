/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:21:21 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 15:15:40 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_action_add(t_param *prm, t_map *map, t_position old_pos)
{
	if (map->map[map->pos.y][map->pos.x] == 'C')
	{
		map->map[map->pos.y][map->pos.x] = '0';
		prm->collected++;
		if (prm->collected == prm->coll_sum)
			prm->unlock_exit = UNLOCK;
	}
	if (map->pos.x != old_pos.x || map->pos.y != old_pos.y)
	{
		prm->steps_old = prm->steps++;
		printf("Your steps: %d\n", prm->steps);
	}
	if (map->map[map->pos.y][map->pos.x] == 'E' && prm->unlock_exit == UNLOCK)
	{
		prm->result = WIN;
		ft_game_end(prm);
	}
}

int	ft_key_action(int key, t_param *prm)
{
	t_map		*map;

	map = prm->map;
	map->old_pos = map->pos;
	if (prm->result == IN_GAME)
	{
		if (key == RIGHT && map->map[map->pos.y][map->pos.x + 1] != '1')
		{
			map->pos.x++;
			map->pl_drc = RIGHT;
		}
		else if (key == LEFT && map->map[map->pos.y][map->pos.x - 1] != '1')
		{
			map->pos.x--;
			map->pl_drc = LEFT;
		}
		else if (key == DOWN && map->map[map->pos.y + 1][map->pos.x] != '1')
			map->pos.y++;
		else if (key == UP && map->map[map->pos.y - 1][map->pos.x] != '1')
			map->pos.y--;
		ft_key_action_add(prm, map, map->old_pos);
	}
	if (key == ESC)
		ft_exit(EXIT, prm);
	return (0);
}
