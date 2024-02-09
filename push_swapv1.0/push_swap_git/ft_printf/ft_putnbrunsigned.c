/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:22:15 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/27 22:26:04 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static unsigned int	ft_putunsinbr(unsigned int n, int *count);

void	ft_unsinbrcompare(unsigned int n, int *count)
{
	int	i;

	ft_putunsinbr(n, count);
	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (*count < i)
		*count = -1;
}

static unsigned int	ft_putunsinbr(unsigned int n, int *count)
{
	if (n < 10)
	{
		n = n + '0';
		if (write (1, &n, 1) == -1)
			*count = *count - 1;
		else
			*count = *count + 1;
		return (n);
	}
	else
	{
		ft_putunsinbr(n / 10, count);
		n = n % 10 + '0';
		if (write (1, &n, 1) == -1)
			*count = *count - 1;
		else
			*count = *count + 1;
		return (n);
	}
}
