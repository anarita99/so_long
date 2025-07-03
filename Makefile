# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-06-22 14:56:45 by adores            #+#    #+#             #
#   Updated: 2025-06-22 14:56:45 by adores           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX = -Lmlx1 -lmlx_Linux -lXext -lX11 -lm

GNL_DIR = get_next_line
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
PRINTF = ft_printf/ft_printstr.c ft_printf/ft_hexaputnbr.c \
	ft_printf/ft_printchar.c ft_printf/ft_printf.c \
	ft_printf/ft_printnbr.c ft_printf/ft_unsputnbr.c ft_printf/ft_printp.c

SRC = main.c cat.c keys.c map.c check_map.c check_map2.c free_things.c copy_map.c $(GNL_SRC) $(PRINTF)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re