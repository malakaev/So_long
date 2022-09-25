/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:06:01 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:21:56 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_img_file(t_param *prm, t_map *map, char *file)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(prm->mlx, file, &map->imgx, &map->imgy);
	if (img_ptr == NULL)
	{
		write(1, "Error\n", 6);
		printf("Can't read file: %s\n", file);
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}

void	init_map_player(t_param *prm, t_map *map)
{
	map->plr[0] = get_img_file(prm, map, "./pic/pl_r00.xpm");
	map->plr[1] = get_img_file(prm, map, "./pic/pl_r01.xpm");
	map->plr[2] = get_img_file(prm, map, "./pic/pl_r02.xpm");
	map->plr[3] = get_img_file(prm, map, "./pic/pl_r03.xpm");
	map->plr[4] = get_img_file(prm, map, "./pic/pl_r04.xpm");
	map->pll[0] = get_img_file(prm, map, "./pic/pl_l00.xpm");
	map->pll[1] = get_img_file(prm, map, "./pic/pl_l01.xpm");
	map->pll[2] = get_img_file(prm, map, "./pic/pl_l02.xpm");
	map->pll[3] = get_img_file(prm, map, "./pic/pl_l03.xpm");
	map->pll[4] = get_img_file(prm, map, "./pic/pl_l04.xpm");
}

void	init_map(t_param *prm, t_map *map)
{
	init_map_player(prm, map);
	map->coll[0] = get_img_file(prm, map, "./pic/coll_0.xpm");
	map->coll[1] = get_img_file(prm, map, "./pic/coll_1.xpm");
	map->coll[2] = get_img_file(prm, map, "./pic/coll_2.xpm");
	map->coll[3] = get_img_file(prm, map, "./pic/coll_3.xpm");
	map->coll[4] = get_img_file(prm, map, "./pic/coll_2.xpm");
	map->coll[5] = get_img_file(prm, map, "./pic/coll_1.xpm");
	map->exit[0] = get_img_file(prm, map, "./pic/ex_0.xpm");
	map->exit[1] = get_img_file(prm, map, "./pic/ex_1.xpm");
	map->exit[2] = get_img_file(prm, map, "./pic/ex_2.xpm");
	map->exit[3] = get_img_file(prm, map, "./pic/ex_3.xpm");
	map->exit[4] = get_img_file(prm, map, "./pic/ex_2.xpm");
	map->exit[5] = get_img_file(prm, map, "./pic/ex_1.xpm");
	map->patr[0] = get_img_file(prm, map, "./pic/bat_0.xpm");
	map->patr[1] = get_img_file(prm, map, "./pic/bat_1.xpm");
	map->patr[2] = get_img_file(prm, map, "./pic/bat_2.xpm");
	map->patr[3] = get_img_file(prm, map, "./pic/bat_1.xpm");
	map->wall = get_img_file(prm, map, "./pic/wallbg.xpm");
	map->tab = get_img_file(prm, map, "./pic/tab_bg.xpm");
	map->bg = get_img_file(prm, map, "./pic/bg.xpm");
	map->sprt_size = map->imgx;
}
