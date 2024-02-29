/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:34:47 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/27 22:37:37 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*fnl_str;
	int			read_return;
	size_t		sizefnl;

	fnl_str = NULL;
	sizefnl = 0;
	read_return = 1;
	while (!fnl_str || (fnl_str[sizefnl] != '\n' && read_return != 0))
	{
		if (buff[0] == '\0')
		{
			ft_memnull(buff, BUFFER_SIZE);
			read_return = read(fd, buff, BUFFER_SIZE);
			if (read_return < 0 || (!fnl_str && read_return == 0))
				return (free(fnl_str), NULL);
		}
		fnl_str = get_next_while(buff, fnl_str);
		if (fnl_str == NULL)
			return (NULL);
		sizefnl = ft_strlen_gnl(fnl_str) - 1;
	}
	return (fnl_str);
}

size_t	ft_check_n(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '\n')
			return (++i);
		i++;
	}
	return ((size_t) 0);
}

char	*get_next_while(char *buff, char *fnl_str)
{
	char	*add_str;
	size_t	i;

	i = ft_check_n(buff);
	if (!i)
	{
		fnl_str = ft_strjoin_fr(fnl_str, buff);
		if (!fnl_str)
			return (ft_memnull(buff, BUFFER_SIZE), NULL);
	}
	else
	{
		add_str = ft_strndup_gnl(buff, i);
		if (!add_str)
			return (ft_memnull(buff, BUFFER_SIZE), free(fnl_str), NULL);
		fnl_str = ft_strjoin_fr(fnl_str, add_str);
		if (!fnl_str)
			return (ft_memnull(buff, BUFFER_SIZE), free(add_str), NULL);
		free(add_str);
		ft_memmove_gnl(buff, buff + i, BUFFER_SIZE - i);
		buff[BUFFER_SIZE - i] = '\0';
	}
	if (!i || i == BUFFER_SIZE)
		ft_memnull(buff, BUFFER_SIZE);
	return (fnl_str);
}

void	*ft_memnull(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*point;

	i = 0;
	point = ptr;
	while (i < num)
	{
		point[i] = '\0';
		i++;
	}
	return (ptr);
}
