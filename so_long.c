/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:10:12 by adores            #+#    #+#             */
/*   Updated: 2025/07/09 14:26:48 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	start_mlx(t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	w = get_map_width(game->map) * SPRITE;
	h = get_map_height(game->map) * SPRITE;
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		return (0);
	if (!load_images(game, w, h) || !load_images2(game, w, h))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game || ac != 2)
		return (1);
	game->map = read_map (av[1]);
	if (!game->map)
		ft_error();
	initiate_things(game);
	initiate_things2(game);
	if (!ft_validatemap(game))
		ft_error();
	if (!start_mlx(game))
	{
		destroy(game);
		return (1);
	}
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (0);
}
