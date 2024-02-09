# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 18:02:28 by tmimault          #+#    #+#              #
#    Updated: 2023/11/27 18:02:32 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CCFlags = -Wall -Wextra -Werror

LIB = ft_printf.h ./libft/libft.h

SRC =	ft_printf.c\
		ft_hexadecimal.c\
		ft_putnbrunsigned.c\
		ft_putnbr.c\
		ft_putstr.c\
		libft/ft_strdup.c\
		libft/ft_calloc.c\
		libft/ft_strlen.c\

OBJ = ${SRC:.c=.o}

all : ${NAME}

$(NAME) : ${OBJ} Makefile
	(cd libft; make all)
	ar -r $@ ./libft/libft.a $^

%.o : %.c ${LIB}
	cc -g ${CCFlags} -o $@ -c $<

clean : 
	(cd libft; make clean)
	rm -f ${OBJ}

fclean : clean
	(cd libft; make fclean)
	rm -f $(NAME)

re : fclean all