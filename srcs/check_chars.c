/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:23:51 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/31 19:36:56 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(int y, int x)
{
	if (player()->x && player()->y)
		fatal_error("Invalid players.Check line %d.\n", (y + 1));
	player()->x = x;
	player()->y = y;
}

void	check_enemy(int y, int x)
{
	if (enemy()->y || enemy()->x)
		fatal_error("Map has more than one enemy. Line %d.\n", (y + 1));
	enemy()->y = y;
	enemy()->x = x;
}

void	check_chars(char *row, int y, int x)
{
	while (row[++x] != '\0' && row)
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P' || row[x] == 'N'))
			fatal_error("Invalid characters. Check line %d.\n", (y + 1));
		if (row[x] == 'P')
			check_player(y, x);
		if (row[x] == 'E')
		{
			if (!map()->valid_exit)
				map()->valid_exit = 1;
			else
				fatal_error("Map has more than one exit. Line %d.\n", (y + 1));
		}
		if (row[x] == 'C')
			map()->coins += 1;
		if ((row[0] != '1' || row[map()->width - 1] != '1') || ((y == 0
					|| y == map()->height - 1) && row[x] != '1'))
			fatal_error("No walls. Check line %d.\n", y + 1);
		if (row[x] == 'N')
			check_enemy(y, x);
	}
}
