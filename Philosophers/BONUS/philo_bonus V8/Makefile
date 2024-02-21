# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/02/06 11:29:10 by gduranti         ###   ########.fr        #
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

vall: re
	valgrind -s --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes --trace-children=yes \
	./$(NAME) 4 600 400 400

hell: re
	valgrind --tool=helgrind --history-level=approx --trace-children=yes ./$(NAME) 2 5000 300 300 3

sanit: fclean
	@$(CC) -fsanitize=thread $(CFLAGS) $(SRCS) -lpthread -o $(NAME)

.PHONY: all clean fclean re bonus vall hell sanit
