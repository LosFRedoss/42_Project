/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:08:51 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/09 16:09:19 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*newarray;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	newarray = malloc(size * nmemb);
	if (newarray == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		newarray[i] = '\0';
		i++;
	}
	return (newarray);
}
