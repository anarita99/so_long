/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-22 15:13:15 by adores            #+#    #+#             */
/*   Updated: 2025-06-22 15:13:15 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *game, int x, int y)
{
	return(game->map[y][x] != '1');
}

/* int	handle_keys(int keycode, t_game *game)
{
	if(keycode == KEY_D)
	{
		game->cat_x += 10;
		game->is_walking = 1;
		game->facing_left = 0;
	}
	else if(keycode == KEY_A)
	{
		game->cat_x -= 10;
		game->is_walking = 1;
		game->facing_left = 1;
	}
	return (0);
} */

int	key_press(int keycode, t_game *game)
{
	int	nx;
	int	ny;

	nx = game->cat_x;
	ny = game->cat_y;
	if(keycode == KEY_W)
		ny--;
	else if(keycode == KEY_S)
		ny++;
	else if(keycode == KEY_A)
	{
		nx--;
		game->facing_left = 1;
	}
	else if(keycode == KEY_D)
	{
		nx++;
		game->facing_left = 0;
	}
	if (can_move(game, nx, ny))
	{
		game->cat_x = nx;
		game->cat_y = ny;
		game->moves++;
		game->walk_timer = 10;
		printf("Moves: %d\n", game->moves);
	}
	return(0);
}

/* int	key_release(int keycode, t_game *game)
{
	if(keycode == KEY_RIGHT)
		game->moving_right = 0;
	if (keycode == KEY_LEFT)
		game->moving_left = 0;
	return (0);
} */