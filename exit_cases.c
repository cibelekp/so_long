/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:08:40 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/28 19:36:52 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(char *msg)
{
	// if lost, render "YOU LOST" / if win render "YOU WIN"
	ft_printf(msg);
	clean_mlx();
	free_matrix();
	if (map()->fd != -1)
		close(map()->fd);
	exit(EXIT_SUCCESS);
}

void	fatal_error(char *msg, int line)
{
	ft_printf("Error\n");
	ft_printf(msg, line);
	clean_mlx();
	free_matrix();
	if (map()->fd != -1)
		close(map()->fd);
	exit(EXIT_FAILURE);
}

// cleanup, destroy images
void	clean_mlx(void)
{
	if (graph()->mlx)
	{
		mlx_destroy_image(graph()->mlx, graph()->background);
		mlx_destroy_image(graph()->mlx, graph()->wall);
		mlx_destroy_image(graph()->mlx, graph()->player[D_UP][0]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_DOWN][0]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_LEFT][0]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_RIGHT][0]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_UP][1]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_DOWN][1]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_LEFT][1]);
		mlx_destroy_image(graph()->mlx, graph()->player[D_RIGHT][1]);
		mlx_destroy_image(graph()->mlx, graph()->exit);
		mlx_destroy_image(graph()->mlx, graph()->coin);
		mlx_destroy_window(graph()->mlx, graph()->window);
		mlx_destroy_display(graph()->mlx);
		free(graph()->mlx);
	}
	ft_printf("mlx cleaned\n");
}

void	free_matrix(void)
{
	int	i;

	i = -1;
	if (map()->matrix)
	{
		while (map()->matrix[++i])
			free(map()->matrix[i]);
		free(map()->matrix);
	}
}

// debug helper
void	display_matrix(int y)
{
	while (map()->matrix[y])
	{
		if (map()->matrix[y][0] == '\n')
			ft_printf("map.matrix[%d] %s", y, map()->matrix[y]);
		else
			ft_printf("map.matrix[%d] %s\n", y, map()->matrix[y]);
		y++;
	}
	ft_printf("map.matrix[%d] %s\n", y, map()->matrix[y]);
	ft_printf("Map height: %d\n", map()->height);
	ft_printf("Map length: %d\n", map()->width);
	ft_printf("Player coordinates: x=%d y=%d.\n", player()->x, player()->y);
}
