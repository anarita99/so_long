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

CFLAGS = -Wall -Wextra -Werror -Imlx -g

REPO := https://github.com/42paris/minilibx-linux.git

MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

GNL_DIR = get_next_line
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

PRINTF = ft_printf/ft_printstr.c ft_printf/ft_hexaputnbr.c \
	ft_printf/ft_printchar.c ft_printf/ft_printf.c \
	ft_printf/ft_printnbr.c ft_printf/ft_unsputnbr.c ft_printf/ft_printp.c

SRC = cat.c keys.c map.c check_map.c check_map2.c free_things.c \
	copy_map.c for_main.c so_long.c $(GNL_SRC) $(PRINTF)
OBJ = $(SRC:.c=.o)

all: $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(MLX_DIR)/libmlx_Linux.a:
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(REPO) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

mlx:
	git clone $(REPO) $(MLX_DIR)

.PHONY: all clean fclean re mlx