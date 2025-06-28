/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:14:08 by adores            #+#    #+#             */
/*   Updated: 2025/06/27 16:43:09 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	load_images(t_game *game, int w, int h)
{
	game->idle_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle00.xpm", &w, &h);
	game->idle_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle01.xpm", &w, &h);
	game->idle_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle02.xpm", &w, &h);
	game->idle_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/idle/idle03.xpm", &w, &h);

	game->walk_right_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/walk0.xpm", &w, &h);
	game->walk_right_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/walk1.xpm", &w, &h);
	game->walk_right_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/walk2.xpm", &w, &h);
	game->walk_right_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_right/walk3.xpm", &w, &h);

	game->walk_left_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/walkl0.xpm", &w, &h);
	game->walk_left_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/walkl1.xpm", &w, &h);
	game->walk_left_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/walkl2.xpm", &w, &h);
	game->walk_left_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_left/walkl3.xpm", &w, &h);

	game->walk_down_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_down/walkd0.xpm", &w, &h);
	game->walk_down_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_down/walkd1.xpm", &w, &h);
	game->walk_down_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_down/walkd2.xpm", &w, &h);
	game->walk_down_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_down/walkd3.xpm", &w, &h);

	game->walk_up_imgs[0] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_up/walkup0.xpm", &w, &h);
	game->walk_up_imgs[1] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_up/walkup1.xpm", &w, &h);
	game->walk_up_imgs[2] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_up/walkup2.xpm", &w, &h);
	game->walk_up_imgs[3] = mlx_xpm_file_to_image(game->mlx, "cats_sprite/walk_up/walkup3.xpm", &w, &h);
}
	
void	load_images2(t_game *game, int w, int h)
{
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/floor/grass.xpm", &w, &h);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/fish/fish3.xpm", &w, &h);
	game->wood_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/wall/wall.xpm", &w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "cats_sprite/exit/exit.xpm", &w, &h);
}

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
		printf("Error\n");
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
	game->map_things.collectibles = 0;
	game->map_things.exit = 0;
	game->map_things.player = 0;
	if (!ft_validatemap(game))
	{
		printf("Error\n");
		exit(0);
	}
	game->mlx = mlx_init();
	w = get_map_width(game->map) * 64;
	h = get_map_height(game->map) * 64;
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	load_images(game, w, h);
	load_images2(game, w, h);
	
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (0);
}
