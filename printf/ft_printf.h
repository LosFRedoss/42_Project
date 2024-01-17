/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:59:42 by tmimault          #+#    #+#             */
/*   Updated: 2023/11/27 18:02:09 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_hexadecimal(int c_size, unsigned long long int n);
int		ft_printf(const char *test, ...);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_nbrcompare(int n, int *count);
void	ft_unsinbrcompare(unsigned int n, int *count);

#endif
