# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/01/25 11:49:11 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = philo
BONUS_NAME = checker

SRCS = srcs/input.c \
	srcs/list_utils.c \
	srcs/philo_utils.c \
	srcs/philo_utils_2.c \
	srcs/philo.c \
	srcs/error.c \
	srcs/actions.c \
	srcs/time_utils.c

BONUS_SRCS = 

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -lpthread -o $(NAME)
	@echo "Let's start !!"

clean:
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

fclean: clean
	
re: fclean all 

bonus:
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(BONUS_SRCS)-lpthread -o $(BONUS_NAME)
	@echo "Here you go!"

vall: re
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes \
	./$(NAME) 6 800 200 200 1

hell: re
	valgrind --tool=helgrind ./$(NAME) 3 700 300 300 1

sanit: fclean
	@$(CC) -fsanitize=thread $(CFLAGS) $(SRCS) -lpthread -o $(NAME)

.PHONY: all clean fclean re bonus
