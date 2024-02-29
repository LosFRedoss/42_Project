# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 21:27:22 by tmimault          #+#    #+#              #
#    Updated: 2024/02/27 21:30:19 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CCFlags = -Wall -Wextra -Werror -g

LIB = pipex.h

LIBFT_H = ./libft/libft.h

LIBFT = ./libft/libft.a

SRC = test.c\

OBJ = ${SRC:%.c=.build/%.o}

.build/%.o : %.c ${LIB} ${LIBFT} $(LIBFT_H) 
	@mkdir -p .build
	cc ${CCFlags} -c $< -o $@

all : mlibft ${NAME}

mlibft:
	@make -C ./libft

$(NAME) : ${OBJ} $(LIB) $(LIBFT_H) Makefile
	cc $(CCFlags) $(OBJ) -o $(NAME) ./libft/libft.a

clean :
	@make -C ./libft clean
	rm -f ${OBJ}
	rm -f ${OBJ_B}

fclean : clean
	@make -C ./libft fclean
	rm -f $(NAME)
	rm -f $(NAME_B)

re : fclean all

.PHONY: all bonus clean fclean re