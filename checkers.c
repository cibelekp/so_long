/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:37:38 by ckoxima-          #+#    #+#             */
/*   Updated: 2023/08/29 21:05:15 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int ac, char *av)
{
	size_t	i;
	int		temp;

	if (ac != 2)
		fatal_error("Wrong arguments. Usage: ./so_long <map.ber>\n", 0);
	i = 0;
	i = (ft_strlen(av)) - 4;
	if ((ft_strncmp(&av[i], ".ber", 4)) != 0 || i == 0)
		fatal_error("Invalid file. Map must have the extention .ber\n", 0);
	temp = open(av, O_RDONLY);
	map()->fd = temp;
	if (map()->fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (0);
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
	// while (map()->enemies_n > 0)
	// {
	// 	map()->en_data[map()->enemies_n]->y = y;
	// 	ft_printf("TEST: map()->en_data[%d]->y = %d", map()->enemies_n, y);
	// }
}

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

void	check_chars(char *row, int y, int x)
{
	while (row[++x] != '\0' && row)
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P' || row[x] == 'N'))
			fatal_error("Invalid characters. Check line %d.\n", (y + 1));
		if (row[x] == 'P')
		{
			if (player()->x && player()->y)
				fatal_error("Invalid players.Check line %d.\n", (y + 1));
			player()->x = x;
			player()->y = y;
		}
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
					|| y == map()->height) && row[x] != '1'))
			fatal_error("No walls. Check line %d.\n", y + 1);
		if (row[x] == 'N')
		{
			// map()->enemies_n += 1; //checking how many enemies
			// map()->enemy_x = x;
			// map()->enemy_y = y;
			if (enemy()->y || enemy()->x)
				fatal_error("Invalid enemies. Check line %d.\n", (y + 1));
			enemy()->y = y;
			enemy()->x = x;
		}
	}
}

void	check_path(int x, int y)
{
	if (map()->matrix[y][x] == 'P' || map()->matrix[y][x] == 'E'
		|| map()->matrix[y][x] == 'C' || map()->matrix[y][x] == '0'
		|| map()->matrix[y][x] == 'N')
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
}
