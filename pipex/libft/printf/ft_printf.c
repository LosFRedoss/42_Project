/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:46:38 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/27 17:58:50 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static int	findtype(char c, va_list ptr);
static int	ft_pointer(void *point);
static int	ft_string(char *s);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += findtype(str[i + 1], ptr);
			i++;
		}
		else if (!(str[i] == '%' && str[i + 1] == '\0'))
		{
			ft_putchar_fd(str[i], 1);
			count ++;
		}
		i++;
	}
	if (str[ft_strlen(str) - 1] == '%' && str[ft_strlen(str) - 2] != '%')
		return (-1);
	return (count);
}

static int	findtype(char c, va_list ptr)
{
	int		str;

	str = 0;
	if (c == 'c')
		ft_putchar_fd((char) va_arg(ptr, int), 1);
	if (c == 's')
		str = ft_string(va_arg(ptr, char *));
	if (c == 'p')
		str = ft_pointer(va_arg(ptr, void *));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ptr, int), &str);
	if (c == 'u')
		ft_putunsinbr(va_arg(ptr, unsigned int), &str);
	if (c == 'x')
		str = ft_hexadecimal(0, va_arg(ptr, unsigned int));
	if (c == 'X')
		str = ft_hexadecimal(1, va_arg(ptr, unsigned int));
	if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == '%' || c == 'c')
		str = 1;
	return (str);
}

static int	ft_pointer(void *point)
{
	if (!point)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
		return (ft_hexadecimal(3, (unsigned long long) &(*point)));
}

static int	ft_string(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
