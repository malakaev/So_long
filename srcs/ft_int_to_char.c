/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:19:55 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/29 18:20:34 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_int_to_char(int num, t_param *prm)
{
	int		n;
	int		len;

	if (num == 0)
	{
		prm->num_str[0] = '0';
		prm->num_str[1] = '\0';
		return ;
	}
	len = 0;
	n = num;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (len > 5)
		len = 5;
	prm->num_str[len--] = '\0';
	while (len >= 0)
	{
		prm->num_str[len--] = num % 10 + '0';
		num /= 10;
	}
}
