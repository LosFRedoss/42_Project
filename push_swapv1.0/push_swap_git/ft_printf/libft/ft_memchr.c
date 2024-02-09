/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:54:18 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/08 16:54:27 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*point;
	char			*point2;

	i = 0;
	point = s;
	while (i < n)
	{
		if (point[i] == (char)c)
		{
			point2 = (char *) &point[i];
			return ((void *)point2);
		}
		i++;
	}
	return (NULL);
}
