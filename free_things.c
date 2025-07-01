/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:46 by adores            #+#    #+#             */
/*   Updated: 2025/07/01 15:57:34 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_game *game)
{
	ft_free(game, game->idle_imgs);
	ft_free(game, game->walk_right_imgs);
	ft_free(game, game->walk_left_imgs);
	ft_free(game, game->walk_down_imgs);
	ft_free(game, game->walk_up_imgs);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->wood_img);
	mlx_destroy_image(game->mlx, game->exit_img);
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