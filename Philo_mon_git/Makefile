# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 19:12:45 by tmimault          #+#    #+#              #
#    Updated: 2024/09/16 19:57:07 by tmimault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BUILD = .build/

CCFlags= -Wall -Wextra -Werror

LIB = philo.h

SRC =	main.c\
		parsing.c\
		philo_action.c\
		mutex_utils.c\
		watcher.c\
		utils.c

OBJ = $(SRC:%.c=$(BUILD)%.o)

DEPS = $(OBJ:.o=.d)

$(BUILD)%.o : %.c $(LIB)
	@mkdir -p .build
	cc $(CCFlags) -c $< -o $@

all : $(NAME)

-include $(DEPS)

$(NAME) : $(OBJ) Makefile
	cc $(CCFlags)  $(OBJ) -o  $(NAME) -lpthread

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	@make all
	
.PHONY: all clean fclean re