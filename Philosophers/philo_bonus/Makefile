# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/02/07 11:18:01 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

NAME = philo_bonus

SRCS = srcs/input_bonus.c \
	srcs/philo_utils_bonus.c \
	srcs/philo_bonus.c \
	srcs/error_bonus.c \
	srcs/time_utils_bonus.c \
	srcs/philo_end_bonus.c \
	srcs/actions_bonus.c \
	srcs/threads_bonus.c

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -lpthread -o $(NAME)
	@echo "Let's start !!"

clean:
	@rm -f $(NAME)

fclean: clean
	
re: fclean all 

bonus: all

.PHONY: all clean fclean re bonus
