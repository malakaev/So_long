/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_for_sl_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:56:29 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:25:20 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_gnl_for_sl_add(t_gnl *gnl, t_gnl_add *gnladd, int fd)
{
	while (gnladd->buf != '\n' || gnladd->i < 0)
	{
		if (gnladd->i++ > 1000)
			ft_err_exit(MAP_ER, "Map is too big. 1000 columns is maximum");
		gnladd->r = read(fd, &gnladd->buf, 1);
		if (gnladd->r == -1)
		{
			gnl->res = -1;
			return ;
		}
		if (gnladd->r == 0)
		{
			gnl->res = 0;
			break ;
		}
		if (gnladd->buf == '\n' && gnladd->i == 0)
			gnladd->i = -1;
		else if (gnladd->r > 0)
			gnladd->temp[gnladd->i] = gnladd->buf;
	}
}

t_gnl	ft_gnl_for_sl(int fd)
{
	t_gnl		gnl;
	t_gnl_add	gnladd;

	gnl.res = 1;
	gnladd.buf = 0;
	gnladd.i = -1;
	ft_gnl_for_sl_add(&gnl, &gnladd, fd);
	if (gnl.res == -1)
		return (gnl);
	gnladd.temp[gnladd.i] = '\0';
	gnl.str_len = gnladd.i;
	gnl.str = (char *)malloc(sizeof(char) * (gnladd.i + 1));
	if (gnl.str == NULL)
		gnl.res = -1;
	while (gnladd.i >= 0 && gnl.res >= 0)
	{
		gnl.str[gnladd.i] = gnladd.temp[gnladd.i];
		gnladd.i--;
	}
	return (gnl);
}
