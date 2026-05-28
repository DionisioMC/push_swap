# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 15:27:36 by dcoelho           #+#    #+#              #
#    Updated: 2026/05/28 14:29:39 by dcoelho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = error_check.c push_swap.c push.c rotate.c swap.c \
	reverse_rotate.c push_swap_utils.c push_swap_utils_2.c insertion.c \
	error_check_utils.c chunk.c chunk_utils.c ft_split parsing_error_check \
	quick.c quick_utils.c

OBJ= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re