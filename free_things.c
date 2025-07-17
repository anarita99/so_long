/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:46 by adores            #+#    #+#             */
/*   Updated: 2025/07/17 15:27:14 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(t_game *game, void **array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (array[i])
			mlx_destroy_image(game->mlx, array[i]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	free_img(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->fish)
		mlx_destroy_image(game->mlx, game->fish);
	if (game->wood)
		mlx_destroy_image(game->mlx, game->wood);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

int	destroy(t_game *game)
{
	if (!game)
		exit(0);
	if (game->mlx)
	{
		ft_free(game, game->idle);
		ft_free(game, game->wr);
		ft_free(game, game->wl);
		ft_free(game, game->wd);
		ft_free(game, game->wu);
		free_img(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	free(game);
	exit(0);
}

void	destroy_map(t_game *game)
{
	if (game->map)
		free_map(game->map);
	free(game);
}
