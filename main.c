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

#include <stdlib.h>
#include "mlx/mlx.h"
#define WIDTH 600
#define HEIGHT 400
int	main()
{
	void	*mlx_ptr;
	void	*mlx_window;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "so_long");
	if(!mlx_window)
		return(free(mlx_ptr), 1);
	y = HEIGHT * 0.1;
	while(y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while(x < WIDTH * 0.9)
		{
			mlx_pixel_put(mlx_ptr, mlx_window, x, y, rand() % 0x1000000);
			x++;
		}
		y++;
	}
	
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}