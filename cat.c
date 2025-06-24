/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:03:58 by adores            #+#    #+#             */
/*   Updated: 2025/06/24 11:32:56 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/// @brief faz a animacao do gato
/// @param game frames
/// @return nao retorna
int	animate_cat(t_game *game)
{
	int tile_size;
	static int	frame;
	static int	counter;

	tile_size = 64;
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	if (game->walk_timer > 0)
	{
		if (game->facing_left)
			mlx_put_image_to_window(game->mlx, game->win, game->walk_left_imgs[frame], game->cat_x * tile_size, game->cat_y * tile_size);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->walk_right_imgs[frame], game->cat_x * tile_size, game->cat_y * tile_size);
		game->walk_timer--;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->idle_imgs[frame],game->cat_x * tile_size, game->cat_y * tile_size);
	}
	counter++;
	if(counter > 4500)
	{
		frame = (frame + 1) % 4;
		counter = 0;
	}
	return(0);
}
