/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:08:59 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:46:47 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_framespeed(void)
{
	if (map()->width * map()->height < 50)
		player()->time_frame = 1500;
	else
		player()->time_frame = 200;
}

void	*convert_img(char *img_path)
{
	void	*address;
	int		w;
	int		h;

	address = mlx_xpm_file_to_image(graph()->mlx, img_path, &w, &h);
	return (address);
}

void	start_game(t_graphics *temp)
{
	graph()->mlx = mlx_init();
	temp->window = mlx_new_window(graph()->mlx, map()->width * 32, map()->height
			* 32, "fat sushi island - the game");
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
	mlx_hook(graph()->window, 17, 0, exit_game, "Exiting game\n");
	mlx_hook(graph()->window, 2, 1L << 0, handle_keys, NULL);
	mlx_loop_hook(graph()->mlx, (void *)render_map, NULL);
	mlx_loop(graph()->mlx);
}
