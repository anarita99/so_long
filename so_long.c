/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:10:12 by adores            #+#    #+#             */
/*   Updated: 2025/07/04 13:45:12 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
