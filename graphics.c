/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/24 20:14:40 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	*graph(void)
{
	static t_graphics	graphics;

	return (&graphics);
}

void	display_steps(void)
{
	char	*str;

	str = ft_itoa(player()->steps);
	str = ft_strjoin("Moves: ", str);
	mlx_string_put(graph()->mlx, graph()->window, 20, 20, WHITE, str);
	free(str);
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
			display_steps();
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_game(void)
{
	// cleanup, destroy images
	ft_printf("exiting game\n");
	exit(1);
}

void	move_player(int x_diff, int y_diff)
{
	if (map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'e')
	{
		if (map()->coins == 0)
			exit(0);
	}
	if (map()->matrix[player()->y + y_diff][player()->x + x_diff] != '1'
		&& map()->matrix[player()->y + y_diff][player()->x + x_diff] != 'e')
	{
		if (map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'c')
		{
			map()->coins -= 1;
			ft_printf("Coins: %d\n", map()->coins);
		}
		map()->matrix[player()->y][player()->x] = 'o';
		player()->x += x_diff;
		player()->y += y_diff;
		map()->matrix[player()->y][player()->x] = 'p';
		player()->steps += 1;
		ft_printf("Steps: %d\n", (player()->steps));
	}
}

int	handle_keys(int keycode)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(graph()->mlx, graph()->window);
		ft_printf("exiting game\n");
		exit(1);
	}
	if (keycode == UP || keycode == W)
		move_player(0, -1);
	else if (keycode == DOWN || keycode == S)
		move_player(0, 1);
	else if (keycode == LEFT || keycode == A)
		move_player(-1, 0);
	else if (keycode == RIGHT || keycode == D)
		move_player(1, 0);
	return (0);
}

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
	mlx_key_hook(graph()->window, handle_keys, NULL);
	mlx_hook(graph()->window, 17, 0, exit_game, NULL);
	mlx_loop_hook(graph()->mlx, render_map, map()->matrix);
	mlx_loop(graph()->mlx);
}
