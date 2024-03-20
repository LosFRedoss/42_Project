# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:14:22 by tmimault          #+#    #+#              #
#    Updated: 2024/03/20 19:52:16 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CCFlags = -g3 -Wall -Wextra -Werror

LIB_H = fract.h

LIBFT_H = ./libft/libft.h

MLIBX_H = ./mlx_linux/mlx.h ./mlx_linux/mlx_int.h

MLIBX = ./mlx_linux/libmlx_Linux.a ./mlx_linux/libmlx.a

LIBFT = ./libft/libft.a

SRC =	first_step.c\
		ft_atof.c\
		nb_cmplx_set.c\
		start_fract.c\
		mlx_basics.c\
		nb_cmplx_calc.c\
		hook_utils.c\
		size_wind_set.c\

OBJ = ${SRC:%.c=.build/%.o}

.build/%.o : %.c ${LIB_H} ${MLIBX} $(MLIBX_H) ${LIBFT} $(LIBFT_H)
	@mkdir -p .build
	cc ${CCFlags} $< -c -o $@ -I/usr/include -I./mlx_linux -O3 -I.

all : mlibft mmlibx ${NAME}

mmlibx:
	@make -C ./mlx_linux

mlibft:
	@make -C ./libft

$(NAME) : ${OBJ} $(LIB_H) $(MLIBX_H) ${LIBFT} $(LIBFT_H) Makefile
	cc $(OBJ) $(CCFlags) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) ./libft/libft.a

clean :
	@make -C ./mlx_linux clean
	@make -C ./libft clean
	rm -f ${OBJ}

fclean : clean
	@make -C ./mlx_linux clean
	@make -C ./libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re