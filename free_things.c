/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:46 by adores            #+#    #+#             */
/*   Updated: 2025/07/03 13:58:25 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free(t_game *game, void **array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
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

int	destroy(t_game *game)
{
	ft_free(game, game->idle);
	ft_free(game, game->walkr);
	ft_free(game, game->walkl);
	ft_free(game, game->walkd);
	ft_free(game, game->walku);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->fish);
	mlx_destroy_image(game->mlx, game->wood);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	free(game);
	exit(0);
}
