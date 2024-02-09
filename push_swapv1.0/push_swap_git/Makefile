# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 18:02:28 by tmimault          #+#    #+#              #
#    Updated: 2024/02/09 19:07:14 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CCFlags = -Wall -Wextra -Werror -g

LIB = push_swap.h

LIB_PF= ./ft_printf/ft_printf.h

SRC =	ft_split.c \
		ft_utils.c \
		list_exploi.c \
		list_info.c \
		list_init.c \
		list_test.c \
		main.c \
		rev_n_rotate.c \
		move_to_b.c \
		sort.c \
		swap_push.c \
		test.c \
		rank.c \

OBJ = ${SRC:.c=.o}

all : ${NAME}

$(NAME) : ${OBJ} $(LIB) $(LIB_PF) Makefile
	(cd ft_printf; make all);
	cc $(CCFlags) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)

%.o : %.c ${LIB} $(LIB_PF)
	cc ${CCFlags} -c $< -o $@

clean :
	(cd ft_printf; make clean)
	rm -f ${OBJ}

fclean : clean
	(cd ft_printf; make fclean)
	rm -f $(NAME)

re : fclean all
