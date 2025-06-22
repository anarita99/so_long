/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-22 14:03:58 by adores            #+#    #+#             */
/*   Updated: 2025-06-22 14:03:58 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate_cat(t_game *game)
{
	static int	frame;
	static int	counter;

	mlx_clear_window(game->mlx, game->win);
	if(game->is_walking)
	{
		if(game->facing_left)
			mlx_put_image_to_window(game->mlx, game->win, game->walk_left_imgs[frame], game->cat_x, game->cat_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->walk_right_imgs[frame], game->cat_x, game->cat_y);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->idle_imgs[frame], game->cat_x, game->cat_y);
	counter++;
	if (counter > 4500)
	{
		frame = (frame + 1) % 4;
		counter = 0;
	}
	return(0);
}