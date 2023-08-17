/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:37:38 by ckoxima-          #+#    #+#             */
/*   Updated: 2023/08/17 19:46:19 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// retangular: strlen
// char check: only 0,1,C,E,P
// min req: at least 1E, 1C, 1P
// walls: first + last lines only 1 / other lines start and end with 1
// valid path:
// handle empty lines?
// error msgs

int	check_chars(char *row)
{
	int	x;

	x = -1;
	while (row[++x] != '\n')
	{
		if (!(row[x] == '0' || row[x] == '1' || row[x] == 'C' || row[x] == 'E'
				|| row[x] == 'P'))
			return (-1);
		if (row[x] == 'P')
		{
			player()->x = x;
			return (1);
		}
		if (row[x] == 'E')
		{
			map()->exit_x = x;
			return (2);
		}
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
	while (map()->matrix[i])
	{
		// ---CHECK RETANGULAR MAPS
		if (ft_strlen(map()->matrix[i]) != (size_t)map()->length)
		{
			// if (map()->matrix[i][map()->length + 1] == '\0')
			// 	break ;
			if (map()->matrix[i][0] == '\n')
				break ;
			// warning about white spaces at the end of the string?
			ft_printf("Error: map is not retangular. Check line %d.\n", i + 1);
		}
		// ---CHECK 0,1,C,E,P
		if (check_chars(map()->matrix[i]) == -1)
			ft_printf("Error: invalid characters. Check line %d.\n", i + 1);
		else if (check_chars(map()->matrix[i]) == 1)
			player()->y = i;
		else if (check_chars(map()->matrix[i]) == 2)
			map()->exit_y = i;
		// CHECK WALLS
		
		i++;
	}
	ft_printf("Character coordinates: x=%d y=%d.\n", player()->x, player()->y);
	ft_printf("Exit coordinates: x=%d y=%d.\n", map()->exit_x, map()->exit_y);
	ft_printf("Checker finished!");
}
