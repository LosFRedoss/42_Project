/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:27:07 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/13 19:27:08 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	newstr = malloc (ft_strlen(s2) + ft_strlen(s1) + 1);
	if (newstr == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (y < ft_strlen(s2))
	{
		newstr[i + y] = s2[y];
		y++;
	}
	newstr[i + y] = '\0';
	return (newstr);
}
