/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:17:35 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/27 22:36:15 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_next_while(char *buff, char *fnl_str);
char	*ft_strjoin_fr(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *s);
void	*ft_memmove_gnl(void *dest, const void *src, size_t n);
char	*ft_strndup_gnl( const char *str, size_t size );
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
void	*ft_memnull(void *ptr, size_t num);
size_t	ft_check_n(char *src);

#endif
