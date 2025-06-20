/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-20 12:14:18 by adores            #+#    #+#             */
/*   Updated: 2025-06-20 12:14:18 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# Contains the X11 and MLX header files
INCLUDES = -I/usr/include -Imlx

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
# Link X11 and MLX
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)