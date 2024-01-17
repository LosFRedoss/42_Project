/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:27 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/07 20:08:31 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*pointsrc;
	char		*pointdest;
	size_t		i;

	i = 0;
	pointsrc = src;
	pointdest = dest;
	if (pointdest > pointsrc)
	{
		i = n;
		while (i-- > 0)
		{
			pointdest[i] = pointsrc[i];
		}
		if (i == 0)
			pointdest[i] = pointsrc[i];
	}
	else
		ft_memcpy(pointdest, pointsrc, n);
	return ((void *)dest);
}
