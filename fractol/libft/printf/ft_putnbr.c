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

void	ft_putnbr(int n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			*count = *count + 11;
		}
		else
		{
			n = -n;
			write(1, "-", 1);
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
		write (1, &n, 1);
		*count = *count + 1;
		return (n);
	}
	else
	{
		ft_putnbr_rec(n / 10, count);
		n = n % 10 + '0';
		write (1, &n, 1);
		*count = *count + 1;
		return (n);
	}
}
