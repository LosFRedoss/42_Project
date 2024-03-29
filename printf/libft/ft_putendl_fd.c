/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:16:12 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/15 17:16:13 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	i;

	i = '\n';
	if (fd < 0)
		return ((void)0);
	write(fd, s, ft_strlen(s));
	write(fd, &i, 1);
}
