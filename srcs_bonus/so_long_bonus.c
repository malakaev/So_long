/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:28:53 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:50:05 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *s)

{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	init_parameters(t_param *prm, t_map *map)
{
	init_map(prm, map);
	prm->bigmap = FALSE;
	prm->win_width = map->sprt_size * map->columns;
	prm->win_height = map->sprt_size * map->rows;
	if (prm->win_width > MAX_RESX || prm->win_height > MAX_RESY)
	{
		prm->win_width = MAX_MAPX;
		prm->win_height = MAX_MAPY;
		prm->bigmap = TRUE;
	}
	prm->map = map;
	prm->collected = 0;
	prm->unlock_exit = LOCK;
	prm->count = 0;
	prm->result = IN_GAME;
}

void	ft_map_check_name(int argc, char **argv)
{
	int	name_len;

	if (argc != 2)
		ft_err_exit(READ_MAP_ER, \
		"Wrong arguments. Required for example ./so_long map.ber");
	name_len = ft_strlen(argv[1]);
	if (argv[1][name_len - 1] != 'r' || argv[1][name_len - 2] != 'e' \
	|| argv[1][name_len - 3] != 'b' || argv[1][name_len - 4] != '.')
		ft_err_exit(READ_MAP_ER, "Map's name must be *.ber");
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_param	prm;

	ft_map_check_name(argc, argv);
	map = ft_read_map(argv[1], &prm);
	prm.mlx = mlx_init();
	if (prm.mlx == NULL)
		ft_err_exit(MLX_ER, "Mlx init error");
	init_parameters(&prm, &map);
	prm.win = mlx_new_window(prm.mlx, prm.win_width, \
	prm.win_height + DY, "So_long_bonus!");
	if (prm.win == NULL)
		ft_err_exit(MLX_ER, "Mlx new window error");
	ft_table_put(&prm, &map);
	if (prm.bigmap == TRUE)
		mlx_loop_hook(prm.mlx, ft_render_map_big, &prm);
	else
		mlx_loop_hook(prm.mlx, ft_render_map, &prm);
	mlx_hook(prm.win, 17, 0, ft_win_closed, 0);
	mlx_hook(prm.win, 2, 0, ft_key_action, &prm);
	mlx_loop(prm.mlx);
}
