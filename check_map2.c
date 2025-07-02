/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:21:39 by adores            #+#    #+#             */
/*   Updated: 2025/07/02 14:16:41 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_rectangular(char **map)
{
	int	row;
	int	width;
	int	col;

	row = 0;
	width = get_map_width(map);
	while(map[row])
	{
		col = 0;
		while(map[row][col] && map[row][col] != '\n')
			col++;
		if (col != width)
			return (0);
		row++;
	}
	return (1);
}

int	ft_validatemap(t_game *game)
{
	if(!check_walls(game->map) || !is_map_rectangular(game->map) || !count_elements(&game->map_things, game->map, &game->collectibles))
		return (0);
	return (1);
}
