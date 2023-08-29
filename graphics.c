/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/29 23:41:45 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_framespeed(void)
{
	if (map()->width * map()->height < 50)
		player()->time_frame = 1500;
	else
		player()->time_frame = 200;
	ft_printf("velocidade %d\n", player()->time_frame);
}

void	start_game(t_graphics *temp)
{
	graph()->mlx = mlx_init();
	temp->window = mlx_new_window(graph()->mlx, map()->width * 32, map()->height
			* 32, "My game");
	temp->wall = convert_img(IMG_WALL);
	temp->background = convert_img(IMG_FLOOR);
	temp->coin = convert_img(IMG_COIN);
	temp->player[D_UP][0] = convert_img(IMG_PLAYER_U1);
	temp->player[D_DOWN][0] = convert_img(IMG_PLAYER_D1);
	temp->player[D_LEFT][0] = convert_img(IMG_PLAYER_L1);
	temp->player[D_RIGHT][0] = convert_img(IMG_PLAYER_R1);
	temp->player[D_UP][1] = convert_img(IMG_PLAYER_U2);
	temp->player[D_DOWN][1] = convert_img(IMG_PLAYER_D2);
	temp->player[D_LEFT][1] = convert_img(IMG_PLAYER_L2);
	temp->player[D_RIGHT][1] = convert_img(IMG_PLAYER_R2);
	temp->exit[0] = convert_img(IMG_EXIT_CLOSED);
	temp->exit[1] = convert_img(IMG_EXIT_OPEN);
	temp->enemy[0] = convert_img(IMG_ENEMY_D1);
	temp->enemy[1] = convert_img(IMG_ENEMY_D2);
	calc_framespeed();
	mlx_hook(graph()->window, 17, 0, exit_game, NULL);
	mlx_hook(graph()->window, 2, 1L << 0, handle_keys, NULL);
	mlx_loop_hook(graph()->mlx, (void *)render_map, NULL);
	mlx_loop(graph()->mlx);
}

void	*convert_img(char *img_path)
{
	void	*address;
	int		w;
	int		h;

	address = mlx_xpm_file_to_image(graph()->mlx, img_path, &w, &h);
	return (address);
}

void	render_map(void)
{
	int			y;
	int			x;
	static int	count;

	y = -1;
	while (map()->matrix[++y])
	{
		x = -1;
		while (map()->matrix[y][++x])
		{
			if (map()->matrix[y][x] == '1')
				put_img(graph()->wall, x, y);
			if (map()->matrix[y][x] == '0' || map()->matrix[y][x] == 'o')
				put_img(graph()->background, x, y);
			if (map()->matrix[y][x] == 'C' || map()->matrix[y][x] == 'c')
				put_img(graph()->coin, x, y);
			if (map()->matrix[y][x] == 'p')
				put_img(graph()->player[player()->dir][player()->frame], x, y);
			if (map()->matrix[y][x] == 'e' && map()->coins != 0)
				put_img(graph()->exit[0], x, y);
			if (map()->matrix[y][x] == 'e' && map()->coins == 0)
				put_img(graph()->exit[1], x, y);
			if (map()->matrix[y][x] == 'N' || map()->matrix[y][x] == 'n')
				put_img(graph()->enemy[player()->frame], x, y);
			display_steps();
		}
	}
	if (count++ > player()->time_frame)
	{
		count = 0;
		player()->frame = (player()->frame == 0);
		if (enemy()->x)
			move_enemy();
	}
}

void	put_img(void *img_address, int x, int y)
{
	mlx_put_image_to_window(graph()->mlx, graph()->window, img_address, x * 32,
			y * 32);
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
