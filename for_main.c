/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:14:08 by adores            #+#    #+#             */
/*   Updated: 2025/07/04 10:58:48 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *game, int w, int h)
{
	game->idle[0] = mlx_xpm_file_to_image(game->mlx, "img/idle00.xpm", &w, &h);
	game->idle[1] = mlx_xpm_file_to_image(game->mlx, "img/idle01.xpm", &w, &h);
	game->idle[2] = mlx_xpm_file_to_image(game->mlx, "img/idle02.xpm", &w, &h);
	game->idle[3] = mlx_xpm_file_to_image(game->mlx, "img/idle03.xpm", &w, &h);
	game->walkr[0] = mlx_xpm_file_to_image(game->mlx, "img/walk0.xpm", &w, &h);
	game->walkr[1] = mlx_xpm_file_to_image(game->mlx, "img/walk1.xpm", &w, &h);
	game->walkr[2] = mlx_xpm_file_to_image(game->mlx, "img/walk2.xpm", &w, &h);
	game->walkr[3] = mlx_xpm_file_to_image(game->mlx, "img/walk3.xpm", &w, &h);
	game->walkl[0] = mlx_xpm_file_to_image(game->mlx, "img/walkl0.xpm", &w, &h);
	game->walkl[1] = mlx_xpm_file_to_image(game->mlx, "img/walkl1.xpm", &w, &h);
	game->walkl[2] = mlx_xpm_file_to_image(game->mlx, "img/walkl2.xpm", &w, &h);
	game->walkl[3] = mlx_xpm_file_to_image(game->mlx, "img/walkl3.xpm", &w, &h);
	if (!game->idle[0] || !game->idle[1] || !game->idle[2] || !game->idle[3]
		|| !game->walkr[0] || !game->walkr[1] || !game->walkr[2]
		|| !game->walkr[3] || !game->walkl[0] || !game->walkl[1]
		|| !game->walkl[2] || !game->walkl[3])
		return (0);
	return (1);
}

int	load_images2(t_game *game, int w, int h)
{
	game->walkd[0] = mlx_xpm_file_to_image(game->mlx, "img/walkd0.xpm", &w, &h);
	game->walkd[1] = mlx_xpm_file_to_image(game->mlx, "img/walkd1.xpm", &w, &h);
	game->walkd[2] = mlx_xpm_file_to_image(game->mlx, "img/walkd2.xpm", &w, &h);
	game->walkd[3] = mlx_xpm_file_to_image(game->mlx, "img/walkd3.xpm", &w, &h);
	game->walku[0] = mlx_xpm_file_to_image(game->mlx, "img/walku0.xpm", &w, &h);
	game->walku[1] = mlx_xpm_file_to_image(game->mlx, "img/walku1.xpm", &w, &h);
	game->walku[2] = mlx_xpm_file_to_image(game->mlx, "img/walku2.xpm", &w, &h);
	game->walku[3] = mlx_xpm_file_to_image(game->mlx, "img/walku3.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "img/grass.xpm", &w, &h);
	game->fish = mlx_xpm_file_to_image(game->mlx, "img/fish3.xpm", &w, &h);
	game->wood = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm", &w, &h);
	if (!game->walkd[0] || !game->walkd[1] || !game->walkd[2] || !game->walkd[3]
		|| !game->walku[0] || !game->walku[1] || !game->walku[2]
		|| !game->walku[3] || !game->floor || !game->fish || !game->wood
		|| !game->exit)
		return (0);
	return (1);
}

void	initiate_things(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (game->map[++row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'P')
			{
				game->cat_x = col;
				game->cat_y = row;
			}
			col++;
		}
	}
	game->is_walking = 0;
	game->map_things.collectibles = 0;
	game->collectibles = 0;
	game->map_things.exit = 0;
	game->map_things.player = 0;
	game->moves = 0;
	game->walk_timer = 4500;
	game->cat_dir = CAT_RIGHT;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	start_mlx(t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	if(!game->mlx)
		return(0);
	w = get_map_width(game->map) * SPRITE;
	h = get_map_height(game->map) * SPRITE;
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if(!game->win)
		return(0);
	if (!load_images(game, w, h) || !load_images2(game, w, h))
		return (0);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (1);
}

