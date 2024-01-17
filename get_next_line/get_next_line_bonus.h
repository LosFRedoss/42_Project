/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:17:35 by tmimault          #+#    #+#             */
/*   Updated: 2023/12/14 18:32:28 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_next_while(char *buff, char *fnl_str);
char	*ft_strjoin_fr(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strndup( const char *str, size_t size );
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memnull(void *ptr, size_t num);
size_t	ft_check_n(char *src);

#endif
