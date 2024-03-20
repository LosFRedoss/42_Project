/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_wind_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:11:17 by tmimault          #+#    #+#             */
/*   Updated: 2024/03/20 19:59:00 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	test_size(char *str)
{
	int i;
	int size_str;

	i = 0;
	size_str = ft_strlen (str);
	while( str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == size_str &&  size_str <= 4)
	{
		i = ft_atoi (str);
		if (i >= 100 && i <= 4000)
			return (i);
	}
	return (-1);
}

t_size_wind	*set_size_wnd_lst(char *str_width, char *str_height)
{
	t_size_wind *size_wind;
	int int_width;
	int int_height;
	
	int_width = test_size(str_width);
	if (!str_height || ft_strlen(str_height) == 0)
		int_height = int_width;
	else 
		int_height = test_size(str_height);
	if (int_height != -1 && int_width != -1)
	{
		size_wind = calloc(1, sizeof(t_size_wind *));
		if (!size_wind)
			return ((void *) 0);
		size_wind->height = int_height;
		size_wind->width = int_width;
		return (size_wind);
	}
		return ((void *) 0);
}

