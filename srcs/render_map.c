/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:37 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:30:13 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_steps(void)
{
	char	*str;
	char	*str2;

	str = ft_itoa(player()->steps);
	str2 = ft_strjoin("Moves: ", str);
	mlx_string_put(graph()->mlx, graph()->window, 20, 20, BLACK, str2);
	free(str);
	free(str2);
}

void	put_img(void *img_address, int x, int y)
{
	mlx_put_image_to_window(graph()->mlx, graph()->window, img_address, x * 32,
		y * 32);
}

void	render_tiles(int x, int y)
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
			render_tiles(x, y);
		}
	}
	if (count++ > player()->time_frame)
	{
		count = 0;
		player()->frame = (player()->frame == 0);
		if (enemy()->x)
			move_enemy(0, 0);
	}
}
