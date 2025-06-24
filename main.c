/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:14:08 by adores            #+#    #+#             */
/*   Updated: 2025/06/24 17:00:02 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		w;
	int		h;
	int		row;
	int		col;

	game = malloc(sizeof(t_game));
	if(!game)
		return(1);
	if (ac != 2)
		return(1);
	game->map = read_map (av[1]);
	if(!game->map)
	{
		printf("Error: map failed to load\n");
    	exit(1);
	}
	row = 0;
	while(game->map[row])
	{
		col = 0;
		while(game->map[row][col])
		{
			if(game->map[row][col] == 'P')
			{
				game->cat_x = col;
				game->cat_y = row;
			}
			col++;
		}
		row++;
	}
	game->is_walking = 0;
	game->facing_left = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 480, "so_long");
	
	//mlx_hook(game->win, EVENT_KEY_RELEASE, 1L<<1, key_release, game);

	game->idle_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle0.xpm", &w, &h);
	game->idle_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle1.xpm", &w, &h);
	game->idle_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle2.xpm", &w, &h);
	game->idle_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle3.xpm", &w, &h);

	game->walk_right_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat5.xpm", &w, &h);
	game->walk_right_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat6.xpm", &w, &h);
	game->walk_right_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat7.xpm", &w, &h);
	game->walk_right_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/cat8.xpm", &w, &h);

	game->walk_left_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat13.xpm", &w, &h);
	game->walk_left_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat14.xpm", &w, &h);
	game->walk_left_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat15.xpm", &w, &h);
	game->walk_left_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/cat16.xpm", &w, &h);

	game->floor_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/floor/floor.xpm", &w, &h);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/fish/fish.xpm", &w, &h);
	
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (0);
}