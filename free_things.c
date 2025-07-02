/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:46 by adores            #+#    #+#             */
/*   Updated: 2025/07/02 14:34:21 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free_map(game);
	free(game->mlx);
	free(game);
	exit(0);
}

void	ft_free(t_game *game, void **array)
{
	int i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, array[i]);
		i++;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}
