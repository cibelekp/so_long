/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/25 16:26:53 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(void)
{
	graph()->mlx = mlx_init();
	graph()->window = mlx_new_window(graph()->mlx, map()->width * 32,
			map()->height * 32, "My game");
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
	mlx_hook(graph()->window, 17, 0, exit_game, NULL);
	mlx_hook(graph()->window, 2, 1L << 0, handle_keys, NULL);
	mlx_loop_hook(graph()->mlx, render_map, NULL);
	mlx_loop(graph()->mlx);
}

int	render_map(void)
{
	int	y;
	int	x;

	y = 0;
	while (map()->matrix[y])
	{
		x = 0;
		while (map()->matrix[y][x])
		{
			if (map()->matrix[y][x] == '1')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->wall, x * 32, y * 32);
			if (map()->matrix[y][x] == '0' || map()->matrix[y][x] == 'o')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->background, x * 32, y * 32);
			if (map()->matrix[y][x] == 'C' || map()->matrix[y][x] == 'c')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->coin, x * 32, y * 32);
			if (map()->matrix[y][x] == 'p')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->player, x * 32, y * 32);
			if (map()->matrix[y][x] == 'e')
				mlx_put_image_to_window(graph()->mlx, graph()->window,
						graph()->exit, x * 32, y * 32);
			display_steps();
			x++;
		}
		y++;
	}
	return (0);
}

void	display_steps(void)
{
	char	*str;
	char	*str2;

	str = ft_itoa(player()->steps);
	str2 = ft_strjoin("Moves: ", str);
	mlx_string_put(graph()->mlx, graph()->window, 20, 20, WHITE, str2);
	free(str);
	free(str2);
}
