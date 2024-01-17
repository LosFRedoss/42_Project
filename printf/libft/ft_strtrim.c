/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:10:49 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/13 20:10:51 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void		addinstr(char const *s1, char *newstr,
					size_t i, size_t size_newstr);
static size_t	startstr(char const *s1, char const *set);
static size_t	comptstr(char const *s1, char const *set, size_t imin);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	size_newstr;
	size_t	i;

	i = startstr(s1, set);
	if (s1[i] == '\0')
		size_newstr = 0;
	else
		size_newstr = (ft_strlen(s1) - i) - (ft_strlen(s1)
				- comptstr(s1, set, i)) + 1;
	newstr = malloc(size_newstr + 1);
	if (newstr == NULL)
		return (NULL);
	addinstr(s1, newstr, i, size_newstr);
	return (newstr);
}

static size_t	startstr(char const *s1, char const *set)
{
	size_t	y;
	size_t	i;
	int		booldog;

	i = 0;
	booldog = 0;
	while (s1[i] != '\0' && booldog != 2)
	{
		y = 0;
		booldog = 0;
		while (set [y] != 0 && booldog != 1)
		{
			if (s1[i] == set[y])
			{
				booldog++;
			}
			else
				y++;
		}
		if (booldog == 1)
			i++;
		else
			booldog = 2;
	}
	return (i);
}

static size_t	comptstr(char const *s1, char const *set, size_t imin)
{
	size_t	i;
	size_t	y;
	int		booldog;

	i = ft_strlen(s1) - 1;
	booldog = 0;
	while (i > imin && booldog != 2)
	{
		y = 0;
		booldog = 0;
		while (set[y] != '\0' && booldog != 1)
		{
			if (s1[i] == set[y])
			{
				booldog = 1;
			}
			else
				y++;
		}
		if (booldog == 1)
			i--;
		else
			booldog = 2 ;
	}
	return (i);
}

static void	addinstr(char const *s1, char *newstr,
			size_t i, size_t size_newstr)
{
	size_t	y;

	y = 0;
	while (y < size_newstr)
	{
		newstr[y] = s1[i + y];
		y++;
	}
	if (y == size_newstr)
		newstr[y] = '\0';
}
