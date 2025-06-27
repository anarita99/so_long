/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:13:15 by adores            #+#    #+#             */
/*   Updated: 2025/06/26 12:45:07 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *game, int x, int y)
{
	int rows;
	int cols;

	if (y < 0)
		return(0);
	rows = 0;
	while(game->map[rows])
		rows++;
	if(y >= rows)
		return (0);
	cols = 0;
	while(game->map[y][cols])
		cols++;
	if (x < 0 || x >= cols)
		return (0);
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
	if(keycode == XK_w)
	{
		ny--;
		game->cat_dir = CAT_UP;
	}
	else if(keycode == XK_s)
	{
		ny++;
		game->cat_dir = CAT_DOWN;
	}
	else if(keycode == XK_a)
	{
		nx--;
		game->cat_dir = CAT_LEFT;
	}
	else if(keycode == XK_d)
	{
		nx++;
		game->cat_dir = CAT_RIGHT;
	}
	else
		return(0);
	if (can_move(game, nx, ny))
	{
		game->cat_x = nx;
		game->cat_y = ny;
		game->moves++;
		game->walk_timer = 4500;
		printf("Moves: %d\n", game->moves);
	}
	return(0);
}

int		destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
/* int	key_release(int keycode, t_game *game)
{
	if(keycode == KEY_RIGHT)
		game->moving_right = 0;
	if (keycode == KEY_LEFT)
		game->moving_left = 0;
	return (0);
} */