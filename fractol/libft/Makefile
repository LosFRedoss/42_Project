# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 16:42:18 by tmimault          #+#    #+#              #
#    Updated: 2024/02/13 20:06:45 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CCFlags= -Wall -Wextra -Werror 

LIB = libft.h ./gnl/get_next_line.h ./printf/ft_printf.h

SRC =	ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_putchar_fd.c\
		ft_striteri.c\
		ft_strmapi.c\
		ft_itoa.c\
		ft_split.c\
		ft_strtrim.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcpy.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\

SRC_PF =	printf/ft_hexadecimal.c\
			printf/ft_printf.c\
			printf/ft_putnbr.c\
			printf/ft_putnbrunsigned.c\

SRC_GNL =	gnl/get_next_line.c\
			gnl/get_next_line_utils.c\

BONUS =	ft_lstmap_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\

OBJ = ${SRC:.c=.o}

OBJ_PF = ${SRC_PF:.c=.o}

OBJ_GNL = ${SRC_GNL:.c=.o}

OBJB = ${OBJ} ${BONUS:.c=.o}

all : ${NAME}

$(NAME) :${OBJ} ${OBJ_PF} ${OBJ_GNL} Makefile
	ar -r $@ $^

%.o : %.c ${LIB}
	cc -g ${CCFlags} -o $@ -c $<

clean : 
	rm -f ${OBJB} ${OBJ_GNL} ${OBJ_PF}

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus: 
	@make SRC="$(SRC) $(BONUS)"