/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:11:49 by adores            #+#    #+#             */
/*   Updated: 2025/07/01 11:36:44 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	is_row_wall(char *row)
{
	int	i;

	i = 0;
	while(row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	are_cols_walls(char **map)
{
	int	row;
	int	len;

	row = 0;
	while(map[row])
	{
		len= 0;
		while(map[row][len])
			len++;
		if (map[row][0] != '1' || map[row][len - 2] != '1')
			return (0);
		row++;
	}
	return (1);	
}

int	check_walls(char **map)
{
	int	row;

	row = 0;
	while(map[row])
		row++;
	row--;
	if (!is_row_wall(map[0]) || !is_row_wall(map[row]))
		return (0);
	if (!are_cols_walls(map))
		return (0);
	return (1);
}

int	count_elements(t_map *things, char **map, int *collectibles)
{
	int	row;
	int col;

	row = 0;
	while(map[row])
	{
		col = 0;
		while(map[row][col])
		{
			if(map[row][col] == 'P')
			{
				things->player++;
				if(things->player != 1)
					return (0);
			}
			else if (map[row][col] == 'E')
			{
				things->exit++;
				if (things->exit != 1)
					return (0);
			}
			else if(map[row][col] == 'C')
			{
				things->collectibles++;
				*collectibles += 1;
			}
			col++;
		}
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