/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:34:14 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/07 16:01:55 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset( void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*point;

	i = 0;
	point = s;
	while (i < n)
	{
		point[i] = (char)c;
		i++;
	}
	return (s);
}
