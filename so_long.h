/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:32:21 by adores            #+#    #+#             */
/*   Updated: 2025/06/27 16:38:34 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

/* #define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3 */

# include "get_next_line/get_next_line.h"
# include "mlx1/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef enum s_cat_dir
{
	CAT_LEFT,
	CAT_RIGHT,
	CAT_UP,
	CAT_DOWN
}				t_cat_dir;

typedef struct s_map
{
	int	player;
	int	exit;
	int collectibles;
}		t_map;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			moves;
	t_cat_dir	cat_dir;
	void		*idle_imgs[4];
	void		*walk_right_imgs[4];
	void		*walk_left_imgs[4];
	void		*walk_up_imgs[4];
	void		*walk_down_imgs[4];
	void		*floor_img;
	void		*wood_img;
	void		*collectible_img;
	int			collectibles;
	void		*exit_img;
	int			cat_x;
	int			cat_y;
	int			is_walking;
	int			walk_timer;
	t_map		map_things;
}				t_game;

char			**read_map(const char *filename);
void			draw_map(t_game *game);
int				animate_cat(t_game *game);
int				key_press(int keycode, t_game *game);
int				destroy(t_game *game);
int				ft_validatemap(t_game *game);

#endif
