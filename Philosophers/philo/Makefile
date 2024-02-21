# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/02/07 11:17:05 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

NAME = philo

BONUS_DIR = .././philo_bonus

SRCS = srcs/input.c \
	srcs/list_utils.c \
	srcs/philo_utils.c \
	srcs/thread_utils.c \
	srcs/philo.c \
	srcs/error.c \
	srcs/actions.c \
	srcs/time_utils.c

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -lpthread -o $(NAME)
	@echo "Let's start !!"

clean:
	@rm -f $(NAME)

fclean: clean
	make clean -C $(BONUS_DIR)
	
re: fclean all 

bonus:
	make all -C $(BONUS_DIR)

.PHONY: all clean fclean re bonus
