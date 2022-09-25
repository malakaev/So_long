/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:15:59 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:40:17 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_rnd_way_patrol(t_map *map, int x, int y)
{
	int	rnd;

	rnd = rand() % 4;
	if (rnd == 0 && (map->map[y - 1][x] == '0' || map->map[y - 1][x] == 'P'))
	{
		map->map[y - 1][x] = 'Z';
		map->map[y][x] = '0';
	}
	if (rnd == 1 && (map->map[y][x - 1] == '0' || map->map[y][x - 1] == 'P'))
	{
		map->map[y][x - 1] = 'Z';
		map->map[y][x] = '0';
	}
	if (rnd == 2 && (map->map[y + 1][x] == '0' || map->map[y + 1][x] == 'P'))
	{
		map->map[y + 1][x] = 'X';
		map->map[y][x] = '0';
	}
	if (rnd == 3 && (map->map[y][x + 1] == '0' || map->map[y][x + 1] == 'P'))
	{
		map->map[y][x + 1] = 'X';
		map->map[y][x] = '0';
	}
}

void	ft_patrol_move(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->columns)
		{
			if (map->map[y][x] == 'Z')
				ft_rnd_way_patrol(map, x, y);
			if (map->map[y][x] == 'X')
				map->map[y][x] = 'Z';
		}
	}
}
