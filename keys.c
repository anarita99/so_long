/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:13:15 by adores            #+#    #+#             */
/*   Updated: 2025/07/09 12:58:20 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int x, int y)
{
	int	rows;
	int	cols;

	if (y < 0)
		return (0);
	rows = 0;
	while (game->map[rows])
		rows++;
	if (y >= rows)
		return (0);
	cols = 0;
	while (game->map[y][cols])
		cols++;
	if (x < 0 || x >= cols)
		return (0);
	return (game->map[y][x] != '1');
}

static int	cat_direction(int keycode, t_game *game, int *nx, int *ny)
{
	if (keycode == XK_w)
	{
		(*ny)--;
		game->cat_dir = CAT_UP;
	}
	else if (keycode == XK_s)
	{
		(*ny)++;
		game->cat_dir = CAT_DOWN;
	}
	else if (keycode == XK_a)
	{
		(*nx)--;
		game->cat_dir = CAT_LEFT;
	}
	else if (keycode == XK_d)
	{
		(*nx)++;
		game->cat_dir = CAT_RIGHT;
	}
	else
		return (0);
	return (1);
}

static void	collect_fish(t_game *game)
{
	if (game->map[game->cat_y][game->cat_x] == 'C')
	{
		game->map[game->cat_y][game->cat_x] = '0';
		game->fishes--;
	}
	if (game->fishes == 0)
	{
		game->map[game->exit_y][game->exit_x] = 'E';
	}
}

static void	set_stuff(t_game *game, int nx, int ny)
{
	game->map[game->cat_y][game->cat_x] = '0';
	game->cat_x = nx;
	game->cat_y = ny;
	game->moves++;
	game->walk_timer = 4500;
}

int	key_press(int keycode, t_game *game)
{
	int	nx;
	int	ny;

	nx = game->cat_x;
	ny = game->cat_y;
	if (keycode == XK_Escape)
		destroy(game);
	if (!cat_direction(keycode, game, &nx, &ny))
		return (0);
	if (can_move(game, nx, ny))
	{
		set_stuff(game, nx, ny);
		collect_fish(game);
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->cat_y][game->cat_x] == 'E' && game->fishes == 0)
		{
			write(1, "YOU WON!\n", 9);
			destroy(game);
		}
		game->map[ny][nx] = 'P';
	}
	return (0);
}
