/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplaying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:26:24 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/26 20:38:10 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keys(int keycode)
{
	if (keycode == ESC)
		exit_game();
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
		{
			ft_printf("You won!\n");
			exit_game();
		}
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
