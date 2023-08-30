/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:26:24 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:19:14 by ckojima-         ###   ########.fr       */
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

void	move_enemy(int y_diff, int x_diff)
{
	if (enemy()->dir == D_UP)
		y_diff = -1;
	if (enemy()->dir == D_DOWN)
		y_diff = 1;
	if (enemy()->dir == D_LEFT)
		x_diff = -1;
	if (enemy()->dir == D_RIGHT)
		x_diff = 1;
	if (map()->matrix[enemy()->y + y_diff][enemy()->x + x_diff] != '1'
		&& map()->matrix[enemy()->y + y_diff][enemy()->x + x_diff] != 'e'
		&& map()->matrix[enemy()->y + y_diff][enemy()->x + x_diff] != 'c')
	{
		map()->matrix[enemy()->y][enemy()->x] = 'o';
		enemy()->x += x_diff;
		enemy()->y += y_diff;
		map()->matrix[enemy()->y][enemy()->x] = 'n';
	}
	else
	{
		srand(time(NULL));
		enemy()->dir = rand() % 4;
	}
	if (enemy()->x == player()->x && enemy()->y == player()->y)
		exit_game("You lost!\n");
}
