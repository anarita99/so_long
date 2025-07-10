/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:21:39 by adores            #+#    #+#             */
/*   Updated: 2025/07/10 12:37:31 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_rectangular(char **map)
{
	int	row;
	int	width;
	int	col;

	row = 0;
	width = get_map_width(map);
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != '\n')
			col++;
		if (col != width)
			return (0);
		row++;
	}
	return (1);
}

static void	flood_fill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == '0' || map_copy[y][x] == 'P' || map_copy[y][x] == 'E'
		|| map_copy[y][x] == 'C')
		map_copy[y][x] = 'F';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

static int	all_reachable(char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_validatemap(t_game *game)
{
	char	**map_copy;

	if (!game->map || !game->map[0])
		return (0);
	map_copy = copy_map(game->map);
	if (!check_walls(game->map) || !is_map_rectangular(game->map)
		|| !count_elements(&game->map_things, game->map, &game->fishes))
	{
		free_map(map_copy);
		return (0);
	}
	flood_fill(map_copy, game->cat_x, game->cat_y);
	if (!all_reachable(map_copy))
	{
		free_map(map_copy);
		return (0);
	}
	free_map(map_copy);
	return (1);
}
