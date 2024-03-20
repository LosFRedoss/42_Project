/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:10:27 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/07 16:07:47 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	size_t	size_dest;
	size_t	allsize;
	size_t	i;

	size_src = ft_strlen(src);
	if ((! dst) && size == 0)
		return (size_src);
	size_dest = ft_strlen(dst);
	i = 0;
	if (size < size_dest)
		allsize = size + size_src;
	else
	{
		allsize = size_src + size_dest;
	}
	while (size >= size_dest + 2 + i && src[i])
	{
		dst[size_dest + i] = src[i];
		i++;
	}
	if (size >= size_dest)
		dst[size_dest + i] = '\0';
	return (allsize);
}
