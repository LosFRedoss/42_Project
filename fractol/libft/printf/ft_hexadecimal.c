/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:30:22 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/27 19:31:53 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	counthex(unsigned long long n);
static void	ifpoint(int *i);

int	ft_hexadecimal(int c_size, unsigned long long n)
{
	char	*tab;
	int		i;
	int		y;
	char	*newstr;

	if (c_size == 1)
		tab = ft_strdup("0123456789ABCDEF");
	if (c_size == 0 || c_size == 3)
		tab = ft_strdup("0123456789abcdef");
	if (!tab)
		return (0);
	i = counthex(n);
	newstr = ft_calloc(sizeof(char), i + 1);
	y = i - 1;
	if (c_size == 3)
		ifpoint(&i);
	while (y >= 0)
	{
		newstr[y] = tab[n % 16];
		n = n / 16;
		y--;
	}
	ft_putstr_fd(newstr, 1);
	return (free(newstr), free(tab), i);
}

static int	counthex(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 15)
	{
		i++;
		n = n / 16;
	}
	i++;
	return (i);
}

static void	ifpoint(int *i)
{
	ft_putstr_fd("0x", 1);
	*i = *i + 2;
}
