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

int	main()
{
	t_game	*game;
	int		w;
	int		h;

	game = malloc(sizeof(t_game));
/* 	if (ac != 2)
		return(1);
	game.map = read_map (av[1]);
	if(!game.map)
		return (1); */
	game->cat_x = 50;
	game->cat_y = 50;
	game->is_walking = 0;
	game->facing_left = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 480, "so_long");
	mlx_key_hook(game->win, handle_keys, game);
	game->idle_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/cat21.xpm", &w, &h);
	game->idle_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/cat22.xpm", &w, &h);
	game->idle_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/cat23.xpm", &w, &h);
	game->idle_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/cat24.xpm", &w, &h);
	game->walk_right_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat5.xpm", &w, &h);
	game->walk_right_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat6.xpm", &w, &h);
	game->walk_right_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat7.xpm", &w, &h);
	game->walk_right_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat8.xpm", &w, &h);
	game->walk_left_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat13.xpm", &w, &h);
	game->walk_left_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat14.xpm", &w, &h);
	game->walk_left_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat15.xpm", &w, &h);
	game->walk_left_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat16.xpm", &w, &h);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (0);

}