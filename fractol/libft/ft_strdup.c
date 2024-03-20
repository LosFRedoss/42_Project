/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:44:26 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/09 15:45:06 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	size_str;
	size_t	i;

	size_str = ft_strlen(s);
	newstr = malloc(size_str + 1);
	if (newstr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size_str)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
