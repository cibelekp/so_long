/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:37:38 by ckoxima-          #+#    #+#             */
/*   Updated: 2023/08/24 17:25:31 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fatal_error(char *msg, int line)
{
	ft_printf(msg, line);
	//cleanup structure?
	ft_printf("Exiting program.\n");
	exit(1);
}

void	check_path(int x, int y)
{
	if (map()->matrix[y][x] == 'P' || map()->matrix[y][x] == 'E'
		|| map()->matrix[y][x] == 'C' || map()->matrix[y][x] == '0')
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
		else
		{
			check_path(x + 1, y);
			check_path(x - 1, y);
			check_path(x, y + 1);
			check_path(x, y - 1);
		}
	}
}

void	check_map_size(int y)
{
	while (map()->matrix[y])
	{
		// recognizes rows that have a different length
		if (ft_strlen(map()->matrix[y]) != (size_t)map()->width)
		{
			// ignores empty lines at the end of map
			if (map()->matrix[y][0] == '\n')
			{
				map()->height = y - 1;
				ft_printf("new map height: %d\n", y);
				break ;
			}
			fatal_error("Error: map is not retangular. Check line %d.\n", y
					+ 1);
		}
		y++;
	}
}

void	check_chars(char *row, int y, int x)
{
	while (row[++x] != '\0' && row)
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P'))
			fatal_error("Error: invalid characters. Check line %d.\n", (y + 1));
		if (row[x] == 'P')
		{
			if (player()->x && player()->y)
				fatal_error("Error: invalid players.Check line %d.\n", (y + 1));
			player()->x = x;
			player()->y = y;
		}
		if (row[x] == 'E')
		{
			if (!map()->valid_exit)
				map()->valid_exit = 1;
			else
				fatal_error("Error: map has more than one exit.\n", 0);
		}
		if (row[x] == 'C')
			map()->coins += 1;
		if ((row[0] != '1' || row[map()->width - 1] != '1') || ((y == 0
					|| y == map()->height) && row[x] != '1'))
			fatal_error("Error: no walls. Check line %d.\n", y + 1);
	}
}

void	check_map(void)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!map()->matrix[y])
		fatal_error("Error: empty map.\n", 0);
	map()->width = ft_strlen(map()->matrix[y]);
	ft_printf("length: %d\n", map()->width);
	//CHECK SIZE
	check_map_size(y);
	while (map()->matrix[y] && y <= map()->height)
	{
		check_chars(map()->matrix[y], y, -1);
		y++;
	}
	//CHECKING C, E, P
	if (!player()->x || !player()->y)
		fatal_error("Error: no player!\n", 0);
	else
	{
		check_path(player()->x, player()->y);
		ft_printf("Player coordinates: x=%d y=%d.\n", player()->x, player()->y);
	}
	if (map()->valid_exit != 2)
		fatal_error("Error: player cannot reach exit.\n", 0);
	if (!map()->coins || map()->coins != map()->valid_coins)
		fatal_error("Error: invalid colectables!\n", 0);
	else
		ft_printf("Number of colectables: %d\n", map()->coins);
	ft_printf("Checker finished!\n");
}
