/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:32:21 by adores            #+#    #+#             */
/*   Updated: 2025/06/25 14:12:52 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

/* #define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

#define EVENT_KEY_PRESS 2
#define EVENT_KEY_RELEASE 3 */

#include "mlx1/mlx.h"
#include "get_next_line/get_next_line.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collectibles;
	int		moves;
	void	*idle_imgs[4];
	void	*walk_right_imgs[4];
	void	*walk_left_imgs[4];
	void	*floor_img;
	void	*wood_img;
	void	*collectible_img;
	void	*exit_img;
	int		cat_x;
	int		cat_y;
	int		is_walking;
	int		facing_left;
	int		walk_timer;
}			t_game;

char	**read_map(const char *filename);
void	draw_map(t_game *game);
int		animate_cat(t_game *game);
int		key_press(int keycode, t_game *game);
int		destroy(t_game *game);

#endif
