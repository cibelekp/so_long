/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/23 16:28:55 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	*graph(void)
{
	static t_graphics	graphics;

	return (&graphics);
}

int	render_map(char **matrix)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == '1')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->wall, x * 32, y * 32);
			if (matrix[y][x] == '0' || matrix[y][x] == 'o')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->background, x * 32, y * 32);
			if (matrix[y][x] == 'C' || matrix[y][x] == 'c')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->coin, x * 32, y * 32);
			if (matrix[y][x] == 'p')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->player, x * 32, y * 32);
			if (matrix[y][x] == 'e')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (0);
}

void	start_window(void)
{
	graph()->mlx = mlx_init();
	graph()->window = mlx_new_window(graph()->mlx, 800, 800, "My game");
	graph()->wall = mlx_xpm_file_to_image(graph()->mlx, "images/wall.xpm",
			&map()->width, &map()->height);
	graph()->background = mlx_xpm_file_to_image(graph()->mlx,
												"images/background.xpm",
												&map()->width,
												&map()->height);
	graph()->coin = mlx_xpm_file_to_image(graph()->mlx,
											"images/collectible.xpm",
											&map()->width,
											&map()->height);
	graph()->player = mlx_xpm_file_to_image(graph()->mlx,
											"images/player.xpm",
											&map()->width,
											&map()->height);
	graph()->exit = mlx_xpm_file_to_image(graph()->mlx,
											"images/exit.xpm",
											&map()->width,
											&map()->height);
	mlx_loop_hook(graph()->mlx, render_map, map()->matrix);
	mlx_loop(graph()->mlx);
}
