# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduranti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:30:55 by gduranti          #+#    #+#              #
#    Updated: 2023/10/19 09:13:45 by gduranti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc

CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
       ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
       ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
       ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	     ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Object files
OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Target library
NAME = libft.a

# Make all: build the library
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

# Compiling individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@

# Make clean: remove object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Make fclean: remove the library and object files
fclean: clean
	rm -f $(NAME)

# Make re: rebuild the project
re: fclean all

# Make bonus: add bonus functions to the library
bonus:	$(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

.PHONY: NAME all clean fclean re bonus
