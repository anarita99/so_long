/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:03:58 by adores            #+#    #+#             */
/*   Updated: 2025/07/02 12:25:29 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/// @brief faz a animacao do gato
/// @param game frames
/// @return nao retorna
int	animate_cat(t_game *game)
{
	int			tile_size;
	static int	f;
	static int	counter;
	int			x;
	int			y;

	tile_size = 64;
	x = game->cat_x * tile_size;
	y = game->cat_y * tile_size;
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	if (game->walk_timer > 0)
	{
		if (game->cat_dir == CAT_LEFT)
			mlx_put_image_to_window(game->mlx, game->win, game->walkl[f], x, y);
		else if (game->cat_dir == CAT_RIGHT)
			mlx_put_image_to_window(game->mlx, game->win, game->walkr[f], x, y);
		else if (game->cat_dir == CAT_DOWN)
			mlx_put_image_to_window(game->mlx, game->win, game->walkd[f], x, y);
		else if (game->cat_dir == CAT_UP)
			mlx_put_image_to_window(game->mlx, game->win, game->walku[f], x, y);
		game->walk_timer--;
	}
	else if (game->map[game->cat_y][game->cat_x] == 'X')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit2, x, y);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->idle[f], x, y);
	counter++;
	if (counter > 4500)
	{
		f = (f + 1) % 4;
		counter = 0;
	}
	return (0);
}
