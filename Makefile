# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 15:27:36 by dcoelho           #+#    #+#              #
#    Updated: 2026/06/03 14:00:17 by dcoelho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

FILES = 0_general_utils.c 0_push_swap.c 0_small_algorithms.c 1_ft_split.c 1_string_handling.c \
		2_error_check_utils.c 2_parsing_error_check.c 3_array_and_list_utils.c 3_general_algorithm_utils.c 3_push.c \
		3_reverse_rotate.c 3_rotate.c 3_swap.c 4_insertion_utils.c 4_insertion.c 5_chunk_utils.c \
		5_chunk.c 6_quick_small_sort.c 6_quick_utils.c 6_quick.c 7_bench.c 7_ft_printf.c

FILES_BONUS = 8_checker_bonus.c 8_error_check_utils_bonus.c 8_ft_split_bonus.c 8_get_next_line_bonus.c \
			8_parsing_error_check_bonus.c 8_push_and_swap_bonus.c 8_rot_and_rev_rot_bonus.c 8_string_handling_bonus.c

OBJ = $(FILES:.c=.o)

OBJ_BONUS = $(FILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean bonus re