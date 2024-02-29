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

unsigned int	ft_putunsinbr(unsigned int n, int *count)
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
		ft_putunsinbr(n / 10, count);
		n = n % 10 + '0';
		write (1, &n, 1);
		*count = *count + 1;
		return (n);
	}
}
