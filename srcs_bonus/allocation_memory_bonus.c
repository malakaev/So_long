/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_memory_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:11:42 by kgolda            #+#    #+#             */
/*   Updated: 2021/12/30 17:20:08 by kgolda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr_b;

	ptr_b = (unsigned char *)b;
	while (len--)
		*ptr_b++ = 0;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	**ft_recalloc_map(char **cur, int count)
{
	int		i;
	char	**new;

	new = ft_calloc(count, sizeof(char *));
	if (new == NULL)
		return (0);
	if (cur == NULL)
		return (new);
	i = -1;
	while (cur[++i] != NULL && i < count)
		new[i] = cur[i];
	free(cur);
	return (new);
}
