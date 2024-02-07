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

#include "push_swap.h"

static long int	signtest(const char *nptr, int *y);

long int	ft_atoi_l(const char *nptr)
{
	long int	nbfinal;
	long int	nbtemp;
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int		y;
	size_t	i;

	i = 0;
	y = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && y == 0)
	{
		if (s1[i] == s2[i])
			y = 0;
		else
			y = (const unsigned char)s1[i] - (const unsigned char)s2[i];
		i++;
	}
	return (y);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*newarray;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX/ size))
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
