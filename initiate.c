/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:27:37 by adores            #+#    #+#             */
/*   Updated: 2025/07/18 12:18:08 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->floor = NULL;
	game->fish = NULL;
	game->exit = NULL;
	game->wood = NULL;
	game->win = NULL;
}

void	initiate_things2(t_game *game)
{
	game->wd[0] = NULL;
	game->wd[1] = NULL;
	game->wd[2] = NULL;
	game->wd[3] = NULL;
	game->idle[0] = NULL;
	game->idle[1] = NULL;
	game->idle[2] = NULL;
	game->idle[3] = NULL;
	game->wl[0] = NULL;
	game->wl[1] = NULL;
	game->wl[2] = NULL;
	game->wl[3] = NULL;
	game->wu[0] = NULL;
	game->wu[1] = NULL;
	game->wu[2] = NULL;
	game->wu[3] = NULL;
	game->wr[0] = NULL;
	game->wr[1] = NULL;
	game->wr[2] = NULL;
	game->wr[3] = NULL;
}

void	initiate_things3(t_game *game)
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
