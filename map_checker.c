/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:37:38 by ckoxima-          #+#    #+#             */
/*   Updated: 2023/08/21 17:52:01 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// retangular: strlen
// char check: only 0,1,C,E,P
// min req: at least 1E, 1C, 1P
// walls: first + last lines only 1 / other lines start and end with 1
// valid path in map (flush sth)
// handle empty lines?
// error msgs

void	fatal_error(char *msg, int line)
{
	//display err message
	ft_printf(msg, line);
	//cleanup structure, close fds?
	//exit program
	ft_printf("Exiting program.\n");
	exit(1);
}

void	check_path(int x, int y)
{
	if (map()->matrix[y][x] == 'P' || map()->matrix[y][x] == 'E'
		|| map()->matrix[y][x] == 'C' || map()->matrix[y][x] == '0')
	{
		if (map()->matrix[y][x] == 'P')
		{
			map()->matrix[y][x] = 'p';
		}
		else if (map()->matrix[y][x] == 'C')
		{
			map()->matrix[y][x] = 'c';
			map()->valid_coins += 1;
		}
		else if (map()->matrix[y][x] == 'E')
		{
			map()->matrix[y][x] = 'e';
			map()->valid_exit += 1;
		}
		else if (map()->matrix[y][x] == '0')
			map()->matrix[y][x] = 'o';
		check_path(x + 1, y);
		check_path(x - 1, y);
		check_path(x, y + 1);
		check_path(x, y - 1);
	}
}

void	check_chars(char *row, int y)
{
	int	x;
	int	last;

	x = 0;
	last = map()->length - 2;
	while (row[x] != '\n' && row)
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P'))
			fatal_error("Error: invalid characters. Check line %d.\n", (y + 1));
		// BUG: does not work if last line doesnt have a \n ... matrix[last] == NULL
		if (row[x] == 'P')
		{
			if (!player()->x && !player()->y)
			{
				player()->x = x;
				player()->y = y;
			}
			else
				fatal_error("Error: map has more than one player.\n", 0);
		}
		if (row[x] == 'E')
		{
			if (!map()->exit_x && !map()->exit_y)
			{
				map()->exit_x = x;
				map()->exit_y = y;
			}
			else
				fatal_error("Error: map has more than one exit.\n", 0);
		}
		if (row[x] == 'C')
			map()->coins += 1;
		if (row[0] != '1' || row[last] != '1')
			fatal_error("Error: map does not have walls. Check line %d.\n", (y
						+ 1));
		if ((y == 0 || y == map()->height) && row[x] != '1')
			ft_printf("No wall: line %d row[%d]: %c\n", y + 1, x, row[x]);
		x++;
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
	map()->length = ft_strlen(map()->matrix[y]);
	ft_printf("length: %d\n", map()->length);
	//CHECK SIZE
	while (map()->matrix[y])
	{
		// ---CHECK RETANGULAR MAPS
		if (ft_strlen(map()->matrix[y]) != (size_t)map()->length)
		{
			if (map()->matrix[y][0] == '\n')
			// ignore empty lines at the end of map
			{
				map()->height = y - 1;
				ft_printf("new map height: %d\n", y);
				break ;
			}
			if ((y == map()->height - 1) && map()->matrix[y][map()->length
				- 1] == '\0')
				break ;
			// warning about white spaces at the end of the string?
			ft_printf("Error: map is not retangular. Check line %d.\n", y + 1);
		}
		y++;
	}
	y = 0;
	while (map()->matrix[y])
	{
		check_chars(map()->matrix[y], y);
		y++;
	}
	//CHECKING C, E, P
	if (!player()->x || !player()->y)
		ft_printf("No Player!\n");
	else
		check_path(player()->x, player()->y);
	// ft_printf("Character coordinates: x=%d y=%d.\n", player()->x,
	// player()->y);
	if (!map()->exit_x || !map()->exit_y || map()->valid_exit != 1)
		ft_printf("Invalid Exit!\n");
	else
		ft_printf("Exit coordinates: x=%d y=%d.\n", map()->exit_x,
				map()->exit_y);
	if (!map()->coins || map()->coins != map()->valid_coins)
		ft_printf("Invalid colectables!\n");
	else
		ft_printf("Number of colectables: %d\n", map()->coins);
	ft_printf("Checker finished!\n");
}
