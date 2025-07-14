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

CFLAGS = -Wall -Wextra -Werror -g

REPO := https://github.com/42paris/minilibx-linux.git

LFLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -Llibft -lft -Lft_printf -lftprintf

MLX_DIR = ./minilibx-linux
GNL_DIR = get_next_line
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

SRC = cat.c keys.c map.c check_map.c check_map2.c free_things.c \
	copy_map.c for_main.c so_long.c $(GNL_SRC)

HEADER = so_long.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME) -I.

clean:
	rm -f $(OBJ) $(LIBFT)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

re: fclean all

mlx:
	git clone $(REPO) $(MLX_DIR)

.PHONY: all clean fclean re mlx