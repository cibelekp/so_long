/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:26:24 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/28 19:50:23 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int keycode)
{
	if (keycode == ESC)
		exit_game("Exiting game\n");
	if (keycode == UP || keycode == W)
		move_player(0, -1, D_UP);
	else if (keycode == DOWN || keycode == S)
		move_player(0, 1, D_DOWN);
	else if (keycode == LEFT || keycode == A)
		move_player(-1, 0, D_LEFT);
	else if (keycode == RIGHT || keycode == D)
		move_player(1, 0, D_RIGHT);
	return (0);
}

void	move_player(int x_diff, int y_diff, t_direction dir)
{
	player()->dir = dir;
	if (map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'e')
	{
		if (map()->coins == 0)
			exit_game("You won!\n");
	}
	if (map()->matrix[player()->y + y_diff][player()->x + x_diff] != '1'
		&& map()->matrix[player()->y + y_diff][player()->x + x_diff] != 'e')
	{
		if (map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'c')
		{
			map()->coins -= 1;
			ft_printf("Coins: %d\n", map()->coins);
		}
		if (map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'n'
			|| map()->matrix[player()->y + y_diff][player()->x + x_diff] == 'N')
			exit_game("You lost!\n");
		map()->matrix[player()->y][player()->x] = 'o';
		player()->x += x_diff;
		player()->y += y_diff;
		map()->matrix[player()->y][player()->x] = 'p';
		player()->steps += 1;
		ft_printf("Steps: %d\n", (player()->steps));
	}
}

void	move_enemy(void)
{
	int	y_diff;
	int	x_diff;

	y_diff = 0;
	x_diff = 0;
	// if (map()->enemy_dir[0] == 0)
	// 	x_diff = 1;
	// else
	// 	x_diff = -1;
	map()->en_dir = D_RIGHT;
	if (map()->en_dir == D_UP)
		y_diff = 1;
	if (map()->en_dir == D_DOWN)
		y_diff = -1;
	if (map()->en_dir == D_LEFT)
		x_diff = -1;
	if (map()->en_dir == D_RIGHT)
		x_diff = 1;
	if (map()->matrix[map()->enemy_y + y_diff][map()->enemy_x + x_diff] != '1'
		&& map()->matrix[map()->enemy_y + y_diff][map()->enemy_x
		+ x_diff] != 'e' && map()->matrix[map()->enemy_y
		+ y_diff][map()->enemy_x + x_diff] != 'c')
	{
		map()->matrix[map()->enemy_y][map()->enemy_x] = 'o';
		map()->enemy_x += x_diff;
		map()->enemy_y += y_diff;
		map()->matrix[map()->enemy_y][map()->enemy_x] = 'n';
		ft_printf("zombie walked: %d\n", map()->enemy_x);
	}
	else
	{
		// map()->enemy_dir[0] = (map()->enemy_dir[0] == 0);
		if (map()->en_dir == D_UP)
			map()->en_dir = D_RIGHT;
		if (map()->en_dir == D_RIGHT)
			map()->en_dir = D_DOWN;
		if (map()->en_dir == D_DOWN)
			map()->en_dir = D_LEFT;
		if (map()->en_dir == D_LEFT)
			map()->en_dir = D_UP;
		ft_printf("zombie direction: %d\n", map()->en_dir);
	}
	if (map()->enemy_x == player()->x && map()->enemy_y == player()->y)
		exit_game("You lost!\n");
	//	if (map()->matrix[map()->enemy_y + y_diff][map()->enemy_x
	// + x_diff] == '1'
	//mudar direcao randomly D_DOWN += 1
}
