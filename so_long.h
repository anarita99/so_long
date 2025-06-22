/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-20 13:32:21 by adores            #+#    #+#             */
/*   Updated: 2025-06-20 13:32:21 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 111
#define KEY_DOWN 116
#define KEY_ESC 9

#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*idle_imgs[4];
	void	*walk_right_imgs[4];
	void	*walk_left_imgs[4];
	int		cat_x;
	int		cat_y;
	int		is_walking;
	int		facing_left; 
}			t_game;

char	**read_map(const char *filename);
int		animate_cat(t_game *game);
int		handle_keys(int keycode, t_game *game);
#endif
