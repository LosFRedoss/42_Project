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
#include "libft.h"

static int	ft_putnbr(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ((void)0);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			n = 0;
		}
		else
		{
			n = -n;
			write(fd, "-", 1);
			ft_putnbr(n, fd);
		}
	}
	else
		ft_putnbr(n, fd);
}

static int	ft_putnbr(int n, int fd)
{
	if (n < 10)
	{
		n = n + '0';
		write (fd, &n, 1);
		return (n);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		n = n % 10 + '0';
		write (fd, &n, 1);
		return (n);
	}
}
