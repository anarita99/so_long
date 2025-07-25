/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:03:58 by adores            #+#    #+#             */
/*   Updated: 2025/07/17 15:32:59 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_cat_sprite(t_game *game, int f, int x, int y)
{
	if (game->walk_timer > 0)
	{
		if (game->cat_dir == CAT_LEFT)
			mlx_put_image_to_window(game->mlx, game->win, game->wl[f], x, y);
		else if (game->cat_dir == CAT_RIGHT)
			mlx_put_image_to_window(game->mlx, game->win, game->wr[f], x, y);
		else if (game->cat_dir == CAT_DOWN)
			mlx_put_image_to_window(game->mlx, game->win, game->wd[f], x, y);
		else if (game->cat_dir == CAT_UP)
			mlx_put_image_to_window(game->mlx, game->win, game->wu[f], x, y);
		game->walk_timer--;
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->idle[f], x, y);
}

int	animate_cat(t_game *game)
{
	static int	f;
	static int	counter;
	int			x;
	int			y;

	x = game->cat_x * SPRITE;
	y = game->cat_y * SPRITE;
	draw_map(game);
	draw_cat_sprite(game, f, x, y);
	counter++;
	if (counter > 4500)
	{
		f = (f + 1) % 4;
		counter = 0;
	}
	return (0);
}
