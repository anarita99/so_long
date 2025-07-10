/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:32:21 by adores            #+#    #+#             */
/*   Updated: 2025/07/10 15:10:57 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define SPRITE 64

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
	int	collectibles;
}		t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			moves;
	t_cat_dir	cat_dir;
	void		*idle[4];
	void		*walkr[4];
	void		*walkl[4];
	void		*walku[4];
	void		*walkd[4];
	void		*floor;
	void		*wood;
	void		*fish;
	int			fishes;
	void		*exit;
	int			cat_x;
	int			cat_y;
	int			exit_x;
	int			exit_y;
	int			is_walking;
	int			walk_timer;
	t_map		map_things;
}				t_game;

int				load_images(t_game *game, int w, int h);
int				load_images2(t_game *game, int w, int h);
void			initiate_things(t_game *game);
void			initiate_things2(t_game *game);
void			ft_error(void);
char			**read_map(const char *filename);
void			draw_map(t_game *game);
int				animate_cat(t_game *game);
int				key_press(int keycode, t_game *game);
int				destroy(t_game *game);
int				ft_validatemap(t_game *game);
int				get_map_width(char **map);
int				get_map_height(char **map);
char			**copy_map(char **map);
void			free_map(char **map);
int				count_elements(t_map *things, char **map, int *collectibles);
int				check_walls(char **map);
void			destroy_map(t_game *game);
#endif
