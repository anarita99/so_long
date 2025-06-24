/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:54:24 by adores            #+#    #+#             */
/*   Updated: 2025/06/24 17:00:02 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(const char *filename)
{
	int	fd;
	int	count;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return(count);
}

char	**read_map(const char *filename)
{
	int		fd;
	int		lines;
	char	*line;
	char	**map;
	int		i;

	lines = count_lines(filename);
	if (lines < 0)
		return (NULL);
	i = 0;
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	while((line = get_next_line(fd)))
		map[i++] = line;
	map[i] = NULL;
	close(fd);
	return (map);
}

void	draw_map(t_game *game)
{
	int	row;
	int	col;
	int	tile_size;

	row = 0;
	tile_size = 64;
	while(game->map[row])
	{
		col = 0;
		while(game->map[row][col])
		{
			//mlx_put_image_to_window(game->mlx, game->win, game->floor_img, col *tile_size, row *tile_size);
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, col * tile_size, row * tile_size);
			else if (game->map[row][col] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, col *tile_size, row *tile_size);
			col++;
		}
		row++;
	}
}