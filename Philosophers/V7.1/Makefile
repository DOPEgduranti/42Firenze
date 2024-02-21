# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/02/01 09:49:34 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

NAME = philo

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
	@rm -f $(BONUS_NAME)

fclean: clean
	
re: fclean all 

vall: re
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes \
	./$(NAME) 3 80 50 50

hell: re
	valgrind --tool=helgrind --history-level=approx ./$(NAME) 5 500 300 300 1

sanit: fclean
	@$(CC) -fsanitize=thread $(CFLAGS) $(SRCS) -lpthread -o $(NAME)

.PHONY: all clean fclean re vall hell sanit
