/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:23:13 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:23:16 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// recognizes rows that have a different length
// updates map height to ignore empty lines after map
void	check_map_size(int y)
{
	while (map()->matrix[y])
	{
		if (ft_strlen(map()->matrix[y]) != (size_t)map()->width)
		{
			if (map()->matrix[y][0] == '\n')
			{
				map()->height = y - 1;
				break ;
			}
			fatal_error("Map is not retangular. Check line %d.\n", y + 1);
		}
		y++;
	}
}

void	check_map(int y)
{
	if (!map()->matrix[y])
		fatal_error("Empty map.\n", 0);
	map()->width = ft_strlen(map()->matrix[y]);
	check_map_size(y);
	while (map()->matrix[y] && y <= map()->height)
	{
		check_chars(map()->matrix[y], y, -1);
		y++;
	}
	if (!player()->x || !player()->y)
		fatal_error("No player!\n", 0);
	else
		check_path(player()->x, player()->y);
	if (map()->valid_exit != 2)
		fatal_error("Player cannot reach exit.\n", 0);
	if (!map()->coins || map()->coins != map()->valid_coins)
		fatal_error("Invalid colectables!\n", 0);
}
