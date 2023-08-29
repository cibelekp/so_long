/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:26:24 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/29 21:52:51 by ckojima-         ###   ########.fr       */
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

void	lost(void)
{
	map()->lost = 1;
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
			// lost();
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
		//random move change
		srand(time(NULL));
		enemy()->dir = rand() % 4; // Generates a number in the range [0, 3]
		printf("Random number: %d\n", enemy()->dir);
		// ft_printf("enemy direction changed: %d\n", enemy()->dir);
	}
	if (enemy()->x == player()->x && enemy()->y == player()->y)
		exit_game("You lost!\n");
}

// void	move_enemy(void)
// {
// 	int	y_diff;
// 	int	x_diff;

// 	y_diff = 0;
// 	x_diff = 0;
// 	// ft_printf("zombie direction: %d\n", map()->en_dir);
// 	if (map()->en_dir == D_UP)
// 		y_diff = -1;
// 	if (map()->en_dir == D_DOWN)
// 		y_diff = 1;
// 	if (map()->en_dir == D_LEFT)
// 		x_diff = -1;
// 	if (map()->en_dir == D_RIGHT)
// 		x_diff = 1;
// 	if (map()->matrix[map()->enemy_y + y_diff][map()->enemy_x + x_diff] != '1'
// 		&& map()->matrix[map()->enemy_y + y_diff][map()->enemy_x
// 		+ x_diff] != 'e' && map()->matrix[map()->enemy_y
// 		+ y_diff][map()->enemy_x + x_diff] != 'c')
// 	{
// 		map()->matrix[map()->enemy_y][map()->enemy_x] = 'o';
// 		map()->enemy_x += x_diff;
// 		map()->enemy_y += y_diff;
// 		map()->matrix[map()->enemy_y][map()->enemy_x] = 'n';
// 		// ft_printf("zombie walked: %d, %d\n", map()->enemy_x, map()->enemy_y);
// 	}
// 	else
// 	{
// 		// SUBSTITUIR POR RANDOM
// 		if (map()->en_dir == D_UP)
// 			map()->en_dir = D_RIGHT;
// 		else if (map()->en_dir == D_RIGHT)
// 			map()->en_dir = D_DOWN;
// 		else if (map()->en_dir == D_DOWN)
// 			map()->en_dir = D_LEFT;
// 		else if (map()->en_dir == D_LEFT)
// 			map()->en_dir = D_UP;
// 		ft_printf("zombie direction changed: %d\n", map()->en_dir);
// 	}
// 	if (map()->enemy_x == player()->x && map()->enemy_y == player()->y)
// 		exit_game("You lost!\n");
// 	//	if (map()->matrix[map()->enemy_y + y_diff][map()->enemy_x
// 	// + x_diff] == '1'
// 	//mudar direcao randomly D_DOWN += 1
// }
