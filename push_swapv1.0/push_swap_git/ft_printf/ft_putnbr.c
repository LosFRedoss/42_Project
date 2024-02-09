/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:19:30 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/15 17:19:31 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnbr_rec(int n, int *count);
static void	ft_putnbr(int n, int *count);

void	ft_nbrcompare(int n, int *count)
{
	int	i;

	ft_putnbr(n, count);
	i = 1;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			i = 11;
			n = 0;
		}
		else
		{
			n = -n;
			i++;
		}
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (*count < i)
		*count = -1;
}

static void	ft_putnbr(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			if (write(1, "-2147483648", 11) == -1)
				*count = *count - 1;
			else
				*count = *count + 11;
		}
		else
		{
			n = -n;
			if (write(1, "-", 1) == -1)
				*count = *count - 1;
			else
				*count = *count + 1;
			ft_putnbr_rec(n, count);
		}
	}
	else
		ft_putnbr_rec(n, count);
}

static int	ft_putnbr_rec(int n, int *count)
{
	if (n < 10)
	{
		n = n + '0';
		if (write(1, &n, 1) == -1)
			*count = *count - 1;
		else
			*count = *count + 1;
		return (n);
	}
	else
	{
		ft_putnbr_rec(n / 10, count);
		n = n % 10 + '0';
		if (write(1, &n, 1) == -1)
			*count = *count - 1;
		else
			*count = *count + 1;
		return (n);
	}
}
