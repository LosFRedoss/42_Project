/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:09:17 by tmimault          #+#    #+#             */
/*   Updated: 2023/12/11 11:09:19 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin_fr(char *s1, char *s2)
{
	char		*newstr;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	newstr = malloc (ft_strlen(s2) + ft_strlen(s1) + 1);
	if (!newstr)
		return (free(s1), NULL);
	if (s1)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[y])
	{
		newstr[i + y] = s2[y];
		y++;
	}
	newstr[i + y] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strndup(const char *str, size_t size)
{
	char	*newstr;
	size_t	i;

	newstr = malloc (sizeof(char) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
