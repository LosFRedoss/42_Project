/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:05:44 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/08 19:05:46 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	size_big;
	size_t	size_lit;

	if (!big && len == 0)
		return (NULL);
	size_big = ft_strlen(big);
	size_lit = ft_strlen(little);
	i = 0;
	if (size_lit == 0)
		return ((char *) big);
	while (i < len && i < size_big + 1)
	{
		y = 0;
		while (big[i + y] == little[y] && big[i + y] != '\0' && y < len - i)
			y++;
		if (y == size_lit)
			return ((char *) &big[i]);
		else
			i++;
	}
	return (NULL);
}
