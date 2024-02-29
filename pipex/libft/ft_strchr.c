/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:25:39 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/08 18:25:41 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	size_s;
	size_t	i;

	size_s = ft_strlen(s);
	i = 0;
	while (i < size_s + 1)
	{
		if (s[i] == (const unsigned char)c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	return (NULL);
}
