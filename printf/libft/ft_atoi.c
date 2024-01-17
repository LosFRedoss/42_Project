/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:34:14 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/07 16:01:55 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long int	signtest(const char *nptr, int *y);

int	ft_atoi(const char *nptr)
{
	unsigned long int	nbfinal;
	unsigned long int	nbtemp;
	long int			i;
	int					y;

	y = 0;
	nbfinal = 0;
	i = signtest(nptr, &y);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbtemp = nbfinal;
		nbfinal = nbfinal * 10 + (nptr[i] - '0');
		i++;
		if (nbtemp > nbfinal && y == 0)
			return (-1);
		else if (nbtemp > nbfinal && y == 1)
			return (0);
	}
	if (y != 0)
		nbfinal = -nbfinal;
	return (nbfinal);
}

static long int	signtest(const char *nptr, int *y)
{
	long int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*y = 1;
		i++;
	}
	return (i);
}
