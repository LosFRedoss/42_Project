/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:13:51 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/14 18:51:35 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	countsize(int n, int *neg);

char	*ft_itoa(int n)
{
	char	*nbstr;
	int		size_nb;
	int		neg;
	int		i;

	size_nb = countsize(n, &neg);
	nbstr = malloc(size_nb + 1);
	i = size_nb;
	if (nbstr == NULL)
		return (NULL);
	nbstr[i] = '\0';
	while (i-- > 1)
	{
		if (n > 0)
			nbstr[i] = n % 10 + '0';
		else
			nbstr[i] = -(n % 10) + '0';
		if (!(neg == 1 && i == 1))
			n = n / 10;
	}
	if (neg == 1)
		nbstr[0] = '-';
	else
		nbstr[0] = n + '0';
	return (nbstr);
}

static int	countsize(int n, int *neg)
{
	int	size_nb;

	size_nb = 1;
	*neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			n++;
		n = -n;
		*neg = 1;
		size_nb++;
	}
	while (n > 9)
	{
		n = n / 10;
		size_nb++;
	}
	return (size_nb);
}
