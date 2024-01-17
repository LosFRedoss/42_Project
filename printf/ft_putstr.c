/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:01:22 by tmimault          #+#    #+#             */
/*   Updated: 2023/12/14 17:01:24 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (write(1, s, ft_strlen(s)) == -1)
		return (-1);
	else
		return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}
