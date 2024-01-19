# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:30:55 by gduranti          #+#    #+#              #
#    Updated: 2023/12/18 10:00:16 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc

CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS =	./ft_atoi.c \
	./ft_bzero.c \
	./ft_calloc.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_isprint.c \
	./ft_itoa.c \
	./ft_lstadd_back.c \
	./ft_lstadd_front.c \
	./ft_lstclear.c \
	./ft_lstdelone.c \
	./ft_lstiter.c \
	./ft_lstlast.c \
	./ft_lstmap.c \
	./ft_lstnew.c \
	./ft_lstsize.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_putchar_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
	./ft_putstr_fd.c \
	./ft_split.c \
	./ft_strchr.c \
	./ft_strdup.c \
	./ft_striteri.c \
	./ft_strjoin.c \
	./ft_strlcat.c \
	./ft_strlcpy.c \
	./ft_strlen.c \
	./ft_strmapi.c \
	./ft_strncmp.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strtrim.c \
	./ft_substr.c \
	./ft_tolower.c \
	./ft_toupper.c \
	./ftprintf/ft_printf.c \
	./ftprintf/ft_printf_hex.c \
	./ftprintf/ft_printf_pointer.c \
	./ftprintf/ft_printf_utils.c \
	./ftprintf/ft_uitoa.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Compiling individual source files
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

# Target library
NAME = libft.a

# Make all: build the library
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a has been created"

# Make clean: remove object files
clean:
	@rm -f $(OBJS)
	@echo "libft objects has been removed"

# Make fclean: remove the library and object files
fclean: clean
	@rm -f $(NAME)
	@echo "libft.a has been removed"

# Make re: rebuild the project
re: fclean all

.PHONY: all clean fclean re
