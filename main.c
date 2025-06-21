/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-20 12:14:08 by adores            #+#    #+#             */
/*   Updated: 2025-06-20 12:14:08 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		w;
	int		h;
	int		frame;

/* 	if (ac != 2)
		return(1);
/* 	game.map = read_map (av[1]);
	if(!game.map)
		return (1); */
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	game.idle_imgs[0] = mlx_xpm_file_to_image(game.mlx, "cats_sprite/idle/idle01.xpm", &w, &h);
	game.idle_imgs[1] = mlx_xpm_file_to_image(game.mlx, "cats_sprite/idle/idle02.xpm", &w, &h);
	frame = 0;
	while (1)
	{
		mlx_put_image_to_window(game.mlx, game.win, game.idle_imgs[frame], 100, 100);
		frame = (frame + 1) % 2; // Toggle between 0 and 1
 		usleep(300000); // 0.3 seconds between frames
		mlx_clear_window(game.mlx, game.win);
	}
	return (0);

}