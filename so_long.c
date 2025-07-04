/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:10:12 by adores            #+#    #+#             */
/*   Updated: 2025/07/04 10:59:00 by adores           ###   ########.fr       */
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
	if(!start_mlx(game))
	{
		destroy(game);
		return (1);
	}
	return (0);
}
