/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:10:12 by adores            #+#    #+#             */
/*   Updated: 2025/07/18 12:17:33 by adores           ###   ########.fr       */
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
	if (!load_images(game, w, h) || !load_images2(game, w, h))
		return (0);
	game->win = mlx_new_window(game->mlx, w, h, "so_long");
	if (!game->win)
		return (0);	
	return (1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static int	is_file_ber(char *filename)
{
	int		i;
	int		j;
	char	*ber;
	char	*temp;

	ber = ".ber";
	i = 0;
	j = 0;
	temp = ft_calloc(5, 1);
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			while (filename[i])
			{
				temp[j] = filename[i];
				j++;
				i++;
			}
			if (ft_strcmp(temp, ber) != 0)
				return (free(temp), 1);
		}
		i++;
	}
	return (free(temp), 0);
}

static void	destroy_and_error(t_game *game)
{
	if (!ft_validatemap(game))
	{
		destroy_map(game);
		ft_error();
	}
	if (!start_mlx(game))
	{
		destroy(game);
		ft_error();
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2 || is_file_ber(av[1]) != 0)
		ft_error();
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->map = read_map (av[1]);
	if (!game->map)
		ft_error();
	initiate_things(game);
	initiate_things2(game);
	initiate_things3(game);
	destroy_and_error(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy, game);
	mlx_loop_hook(game->mlx, animate_cat, game);
	mlx_loop(game->mlx);
	return (0);
}
