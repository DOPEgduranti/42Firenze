# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:48:55 by gduranti          #+#    #+#              #
#    Updated: 2023/12/21 12:29:52 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

NAME = so_long

MAP1 = map/mapxmas.ber
MAP2 = map/mapxmas4.ber
MAP3 = map/mapxmas3.ber
MAP4 = map/mapofficial.ber

SRCS = src/so_long.c \
	src/so_long_utils.c \
	src/collectible.c \
	src/read_map.c \
	src/read_map_2.c \
	src/player.c \
	src/errors.c \
	src/game.c \
	src/walls.c \
	src/exit.c \
	src/movement.c \
	src/enemy.c \
	src/enemy_basic.c \
	src/scores.c

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@make all -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(SRCS) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "Let's play !!"

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@rm -f $(NAME)

re: fclean all

replay:
	@rm -f $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Let's play !!"

play1:
	@echo "\n\n\n********************\n\nSave the Christmas!!\nLv. Snowflake\n\n********************\n\n\n"
	@sleep 1
	@./so_long $(MAP1)

play2:
	@echo "\n\n\n********************\n\nSave the Christmas!!\nLv. Jingle Bells\n\n********************\n\n\n"
	@sleep 1
	@./so_long $(MAP2)

play3:
	@echo "\n\n\n********************\n\nSave the Christmas!!\nLv. Snowtrial\n\n********************\n\n\n"
	@sleep 1
	@./so_long $(MAP3)

play4:
	@echo "\n\n\n********************\n\nSave the Christmas!!\nLv. Let it Snow\n\n********************\n\n\n"
	@sleep 1
	@./so_long $(MAP4)

.PHONY: all clean fclean re replay play1 play2 play3 play4
