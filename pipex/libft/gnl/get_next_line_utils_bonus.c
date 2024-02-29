/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:09:17 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/27 22:37:09 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_fr(char *s1, char *s2)
{
	char		*newstr;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	newstr = malloc (ft_strlen_gnl(s2) + ft_strlen_gnl(s1) + 1);
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

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove_gnl(void *dest, const void *src, size_t n)
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
		ft_memcpy_gnl(pointdest, pointsrc, n);
	return ((void *)dest);
}

void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
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
