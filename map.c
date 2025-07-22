/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:54:24 by adores            #+#    #+#             */
/*   Updated: 2025/07/22 12:05:03 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (count);
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
	while (i < lines)
	{
		line = get_next_line(fd);
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->fish, x
					* SPRITE, y * SPRITE);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wood, x
					* SPRITE, y * SPRITE);
			else if (game->map[y][x] == 'E' && game->fishes == 0)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x
					* SPRITE, y * SPRITE);
			}
			else if (game->map[y][x] != 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, x
					* SPRITE, y * SPRITE);
		}
	}
}

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
