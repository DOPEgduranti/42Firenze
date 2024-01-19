# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2024/01/15 09:52:50 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = server
CLIENT = client

SRCS_C = srcs/client.c
SRCS_S = srcs/server.c

BONUS_SRCS_C = srcs/client_bonus.c
BONUS_SRCS_S = srcs/server_bonus.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)
	@echo "Let's start !!"

bonus:
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(BONUS_SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(BONUS_SRCS_C) $(LIBFT) -o $(CLIENT)
	@echo "Let's bonus !!"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@rm -f $(CLIENT)

re: fclean all

ciao:
	@echo "scemo chi legge"

rebu:
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) -o $(CLIENT)
	@echo "Done !!"

.PHONY: all bonus clean fclean re rebu ciao
