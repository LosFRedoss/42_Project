/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:04:50 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/13 18:04:52 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	y;
	size_t			i;

	i = 0;
	if (start > ft_strlen (s))
	{
		start = 0;
		len = 0;
	}
	if (len >= ft_strlen(s) || start + len >= ft_strlen(s) + 1)
		len = ft_strlen(s) - start;
	y = start;
	newstr = malloc((len) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s[y + i] != '\0' && i < len && start < ft_strlen(s)
		&& len > 0 && start < INT_MAX)
	{
		newstr[i] = s[y + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
