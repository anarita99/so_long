/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-22 15:13:15 by adores            #+#    #+#             */
/*   Updated: 2025-06-22 15:13:15 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int keycode, t_game *game)
{
	if(keycode == KEY_RIGHT)
	{
		game->cat_x += 10;
		game->is_walking = 1;
		game->facing_left = 0;
	}
	else if(keycode == KEY_LEFT)
	{
		game->cat_x -= 10;
		game->is_walking = 1;
		game->facing_left = 1;
	}
	return (0);
}