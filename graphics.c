/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/25 20:31:40 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_graphics *temp)
{
	graph()->mlx = mlx_init();
	temp->window = mlx_new_window(graph()->mlx, map()->width * 32, map()->height
			* 32, "My game");
	temp->wall = convert_img(WALL_IMG);
	temp->background = convert_img(FLOOR_IMG);
	temp->coin = convert_img(COIN_IMG);
	temp->player = convert_img(PLAYER_IMG);
	temp->exit = convert_img(EXIT_IMG);
	mlx_hook(graph()->window, 17, 0, exit_game, NULL);
	mlx_hook(graph()->window, 2, 1L << 0, handle_keys, NULL);
	mlx_loop_hook(graph()->mlx, render_map, NULL);
	mlx_loop(graph()->mlx);
}

void	*convert_img(char *img_path)
{
	void	*address;

	address = mlx_xpm_file_to_image(graph()->mlx, img_path, &map()->width,
			&map()->height);
	return (address);
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
				put_img(graph()->wall, x, y);
			if (map()->matrix[y][x] == '0' || map()->matrix[y][x] == 'o')
				put_img(graph()->background, x, y);
			if (map()->matrix[y][x] == 'C' || map()->matrix[y][x] == 'c')
				put_img(graph()->coin, x, y);
			if (map()->matrix[y][x] == 'p')
				put_img(graph()->player, x, y);
			if (map()->matrix[y][x] == 'e')
				put_img(graph()->exit, x, y);
			display_steps();
			x++;
		}
		y++;
	}
	return (0);
}

void	put_img(void *img_address, int x, int y)
{
	mlx_put_image_to_window(graph()->mlx, graph()->window, img_address, 
		x * 32, y * 32);
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
