/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:45:30 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:21:56 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_symbol(char c, t_param *prm)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'Z')
	{
		if (c == 'E')
			prm->exits++;
		if (c == 'Z')
			prm->patrols++;
		if (c == 'C')
			prm->coll_sum++;
		return (TRUE);
	}
	return (FALSE);
}

void	ft_map_check(t_map *map, t_param *prm)
{
	int	i;
	int	row;

	row = 0;
	while (row < map->rows)
	{
		i = 0;
		while (map->map[row][i] != '\0')
		{
			if ((row == 0 || row == map->rows - 1) && map->map[row][i] != '1')
				ft_err_exit(READ_MAP_ER, "Map must be closed around with '1'.");
			if (!ft_check_symbol(map->map[row][i], prm))
				ft_err_exit(READ_MAP_ER, "Map error. \
				Allowed only symbols: 10CEPZ.");
			i++;
		}
		if (row > 0 && map->columns != i && i > 0)
			ft_err_exit(READ_MAP_ER, "Map must be rectangle.");
		map->columns = i;
		if (map->map[row][0] != '1' || map->map[row][i - 1] != '1')
			ft_err_exit(READ_MAP_ER, "Map must be closed around with '1'.");
		row++;
	}
}

t_position	ft_pl_pos(t_param *prm, t_map *map)
{
	int			x;
	int			y;
	t_position	player_pos;

	prm->players = 0;
	prm->coll_sum = 0;
	prm->patrols = 0;
	prm->exits = 0;
	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x > -2 && map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'P')
			{
				player_pos.x = x;
				player_pos.y = y;
				map->map[y][x] = '0';
				prm->players++;
			}
		}
	}
	return (player_pos);
}

t_gnl	ft_read_map_gnl_handler(t_map *map, int fd, int *i)
{
	t_gnl	gnl;

	*i = 0;
	gnl = ft_gnl_for_sl(fd);
	if (gnl.res == 1)
	{
		map->map = (char **)ft_calloc(2, sizeof(char *));
		map->map[0] = gnl.str;
	}
	while (gnl.res == 1)
	{
		gnl = ft_gnl_for_sl(fd);
		if (gnl.str_len > 0 && gnl.res >= 0)
		{
			*i = *i + 1;
			map->map = ft_recalloc_map(map->map, *(i) + 2);
			map->map[*i] = gnl.str;
		}
		else
		{
			free (gnl.str);
			gnl.str = NULL;
		}
	}
	return (gnl);
}

t_map	ft_read_map(char *path, t_param *prm)
{
	int		fd;
	int		i;
	t_map	map;
	t_gnl	gnl;

	fd = open(path, O_RDONLY);
	gnl = ft_read_map_gnl_handler(&map, fd, &i);
	close(fd);
	if (gnl.res == 0 && i == 0)
		ft_err_exit(READ_MAP_ER, "Map file error or empty.");
	if (gnl.res == -1)
		ft_err_exit(READ_MAP_ER, "Error reading map file");
	map.rows = i + 1;
	map.columns = ft_strlen(map.map[i - 1]);
	map.pos = ft_pl_pos(prm, &map);
	ft_map_check(&map, prm);
	if (prm->players != 1 || prm->coll_sum < 1 || prm->exits < 1)
		ft_err_exit(READ_MAP_ER, "Map must have at least one E, \
		one C and only one P.");
	return (map);
}
