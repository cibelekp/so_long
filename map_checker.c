/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:37:38 by ckoxima-          #+#    #+#             */
/*   Updated: 2023/08/21 12:44:38 by ckojima-         ###   ########.fr       */
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

// int	check_path(void)
// {
// }

int	check_chars(char *row, int y)
{
	int	x;
	int	last;

	x = -1;
	last = map()->length - 2;
	while (row[++x] != '\n' && row)
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P'))
			return (-1);
		// BUG: does not work if last line doesnt have a \n ... matrix[last] == NULL
		if (row[x] == 'P')
		{
			if (!player()->x && !player()->y)
			{
				player()->x = x;
				player()->y = y;
			}
			else
				ft_printf("Error: map has more than one player.\n");
		}
		if (row[x] == 'E')
		{
			if (!map()->exit_x && !map()->exit_y)
			{
				map()->exit_x = x;
				map()->exit_y = y;
			}
			else
				ft_printf("Error: map has more than one exit.\n");
		}
		if (row[x] == 'C')
			map()->collectable = 1;
		if (row[0] != '1' || row[last] != '1')
		{
			// ft_printf("row[0]: %c  row[last]: %c\n", row[0], row[last]);
			return (-2);
		}
		// ft_printf("y == %d, map()->height == %d\n", y, map()->height);
		if ((y == 0 || y == map()->height) && row[x] != '1')
			ft_printf("No wall: line %d row[%d]: %c\n", y + 1, x, row[x]);
	}
	return (0);
}

void	check_map(void)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	map()->length = ft_strlen(map()->matrix[i]);
	ft_printf("length: %d\n", map()->length);
	//CHECK SIZE
	while (map()->matrix[i])
	{
		// ---CHECK RETANGULAR MAPS
		if (ft_strlen(map()->matrix[i]) != (size_t)map()->length)
		{
			if (map()->matrix[i][0] == '\n')
			// ignore empty lines at the end of map
			{
				map()->height = i - 1;
				ft_printf("new map height: %d\n", i);
				break ;
			}
			if ((i == map()->height - 1) && map()->matrix[i][map()->length
				- 1] == '\0')
				break ;
			// warning about white spaces at the end of the string?
			ft_printf("Error: map is not retangular. Check line %d.\n", i + 1);
		}
		i++;
	}
	i = 0;
	while (map()->matrix[i])
	{
		// ---CHECK 0,1,C,E,P
		if (check_chars(map()->matrix[i], i) == -1)
			ft_printf("Error: invalid characters. Check line %d.\n", i + 1);
		// CHECK WALLS
		if (check_chars(map()->matrix[i], i) == -2)
			// calling the function too many times
			ft_printf("Error: map does not have walls. Check line %d.\n", (i
						+ 1));
		// CHECK IF THERE ARE CHARACTERS, COLLECTIBLES AND EXIT
		i++;
	}
	if (!player()->x || !player()->y)
		ft_printf("No Player!\n");
	else
		ft_printf("Character coordinates: x=%d y=%d.\n", player()->x,
				player()->y);
	if (!map()->exit_x || !map()->exit_y)
		ft_printf("No Exit!\n");
	else
		ft_printf("Exit coordinates: x=%d y=%d.\n", map()->exit_x,
				map()->exit_y);
	if (!map()->collectable)
		ft_printf("No Collectables!\n");
	ft_printf("Checker finished!");
}
