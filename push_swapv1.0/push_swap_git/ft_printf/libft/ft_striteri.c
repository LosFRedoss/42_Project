/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:36 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/15 16:34:07 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	size_s;
	size_t	i;

	size_s = ft_strlen(s);
	i = 0;
	while (i < size_s)
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
