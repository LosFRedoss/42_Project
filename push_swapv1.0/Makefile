# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 18:02:28 by tmimault          #+#    #+#              #
#    Updated: 2024/02/07 14:42:08 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CCFlags = -Wall -Wextra -Werror -g

LIB = push_swap.h

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

$(NAME) : ${OBJ} $(LIB) Makefile
	cc $(CCFlags) $(OBJ) -o $(NAME)
	make clean

%.o : %.c ${LIB}
	cc ${CCFlags} -c $< -o $@

clean : 
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME)

re : fclean all
