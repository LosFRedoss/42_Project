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

static int	findtype(char c, va_list ptr);
static int	ft_pointer(void *point);
static int	ft_string(char *s);
static int	ft_nottype(char c);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		error;
	int		count;

	i = -1;
	error = 0;
	count = 0;
	va_start(ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && (str[i + 1] != '\0'))
		{
			error = findtype(str[i + 1], ptr);
			i++;
		}
		else if (!(str[i] == '%'))
			error = ft_putchar(str[i]);
		if (error < 0)
			return (va_end(ptr), -1);
		count += error;
	}
	if (str[ft_strlen(str) - 1] == '%' && str[ft_strlen(str) - 2] != '%')
		return (va_end(ptr), -1);
	return (va_end(ptr), count);
}

static int	findtype(char c, va_list ptr)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_putchar((char) va_arg(ptr, int));
	else if (c == 's')
		count = ft_string(va_arg(ptr, char *));
	else if (c == 'p')
		count = ft_pointer(va_arg(ptr, void *));
	else if (c == 'd' || c == 'i')
		ft_nbrcompare(va_arg(ptr, int), &count);
	else if (c == 'u')
		ft_unsinbrcompare(va_arg(ptr, unsigned int), &count);
	else if (c == 'x')
		count = ft_hexadecimal(0, va_arg(ptr, unsigned int));
	else if (c == 'X')
		count = ft_hexadecimal(1, va_arg(ptr, unsigned int));
	else if (c == '%')
		count = ft_putstr("%");
	else
		count = ft_nottype(c);
	return (count);
}

static int	ft_pointer(void *point)
{
	if (!point)
		return (ft_putstr("(nil)"));
	else
		return (ft_hexadecimal(3, (unsigned long long) &(*point)));
}

static int	ft_string(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

static int	ft_nottype(char c)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (2);
}
