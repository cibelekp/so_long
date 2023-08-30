/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:24:29 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:24:32 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_path(int x, int y)
{
	if (map()->matrix[y][x] == 'P')
		map()->matrix[y][x] = 'p';
	if (map()->matrix[y][x] == 'C')
	{
		map()->matrix[y][x] = 'c';
		map()->valid_coins += 1;
	}
	if (map()->matrix[y][x] == '0')
		map()->matrix[y][x] = 'o';
	if (map()->matrix[y][x] == 'E')
	{
		map()->matrix[y][x] = 'e';
		map()->valid_exit += 1;
	}
	if (map()->matrix[y][x] == 'N')
		map()->matrix[y][x] = 'n';
	else
	{
		check_path(x + 1, y);
		check_path(x - 1, y);
		check_path(x, y + 1);
		check_path(x, y - 1);
	}
}

void	check_path(int x, int y)
{
	if (map()->matrix[y][x] == 'P' || map()->matrix[y][x] == 'E'
		|| map()->matrix[y][x] == 'C' || map()->matrix[y][x] == '0'
		|| map()->matrix[y][x] == 'N')
	{
		mark_path(x, y);
	}
}
