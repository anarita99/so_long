/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:14:08 by adores            #+#    #+#             */
/*   Updated: 2025/07/17 15:39:45 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_images(t_game *game, int w, int h)
{
	game->idle[0] = mlx_xpm_file_to_image(game->mlx, "textures/i0.xpm", &w, &h);
	game->idle[1] = mlx_xpm_file_to_image(game->mlx, "textures/i1.xpm", &w, &h);
	game->idle[2] = mlx_xpm_file_to_image(game->mlx, "textures/i2.xpm", &w, &h);
	game->idle[3] = mlx_xpm_file_to_image(game->mlx, "textures/i3.xpm", &w, &h);
	game->wr[0] = mlx_xpm_file_to_image(game->mlx, "textures/wr0.xpm", &w, &h);
	game->wr[1] = mlx_xpm_file_to_image(game->mlx, "textures/wr1.xpm", &w, &h);
	game->wr[2] = mlx_xpm_file_to_image(game->mlx, "textures/wr2.xpm", &w, &h);
	game->wr[3] = mlx_xpm_file_to_image(game->mlx, "textures/wr3.xpm", &w, &h);
	game->wl[0] = mlx_xpm_file_to_image(game->mlx, "textures/wl0.xpm", &w, &h);
	game->wl[1] = mlx_xpm_file_to_image(game->mlx, "textures/wl1.xpm", &w, &h);
	game->wl[2] = mlx_xpm_file_to_image(game->mlx, "textures/wl2.xpm", &w, &h);
	game->wl[3] = mlx_xpm_file_to_image(game->mlx, "textures/wl3.xpm", &w, &h);
	if (!game->idle[0] || !game->idle[1] || !game->idle[2] || !game->idle[3]
		|| !game->wr[0] || !game->wr[1] || !game->wr[2]
		|| !game->wr[3] || !game->wl[0] || !game->wl[1]
		|| !game->wl[2] || !game->wl[3])
		return (0);
	return (1);
}

int	load_images2(t_game *game, int w, int h)
{
	game->wd[0] = mlx_xpm_file_to_image(game->mlx, "textures/wd0.xpm", &w, &h);
	game->wd[1] = mlx_xpm_file_to_image(game->mlx, "textures/wd1.xpm", &w, &h);
	game->wd[2] = mlx_xpm_file_to_image(game->mlx, "textures/wd2.xpm", &w, &h);
	game->wd[3] = mlx_xpm_file_to_image(game->mlx, "textures/wd3.xpm", &w, &h);
	game->wu[0] = mlx_xpm_file_to_image(game->mlx, "textures/wu0.xpm", &w, &h);
	game->wu[1] = mlx_xpm_file_to_image(game->mlx, "textures/wu1.xpm", &w, &h);
	game->wu[2] = mlx_xpm_file_to_image(game->mlx, "textures/wu2.xpm", &w, &h);
	game->wu[3] = mlx_xpm_file_to_image(game->mlx, "textures/wu3.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/fl.xpm", &w, &h);
	game->fish = mlx_xpm_file_to_image(game->mlx, "textures/fish.xpm", &w, &h);
	game->wood = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);
	if (!game->wd[0] || !game->wd[1] || !game->wd[2] || !game->wd[3]
		|| !game->wu[0] || !game->wu[1] || !game->wu[2]
		|| !game->wu[3] || !game->floor || !game->fish || !game->wood
		|| !game->exit)
		return (0);
	return (1);
}

void	initiate_things(t_game *game)
{
	game->cat_x = 0;
	game->cat_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->is_walking = 0;
	game->map_things.collectibles = 0;
	game->fishes = 0;
	game->map_things.exit = 0;
	game->map_things.player = 0;
	game->moves = 0;
	game->walk_timer = 4500;
	game->cat_dir = CAT_RIGHT;
}

void	initiate_things2(t_game *game)
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
			else if (game->map[row][col] == 'E')
			{
				game->exit_x = col;
				game->exit_y = row;
			}
			col++;
		}
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
