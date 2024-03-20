/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:21:51 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/07 19:22:10 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*point1;
	char		*point2;
	size_t		i;

	point1 = src;
	point2 = dest;
	i = 0;
	while (i < n && &point2[i] != &point1[i + 0])
	{
		point2[i] = point1[i];
		i++;
	}
	return ((void *)dest);
}
