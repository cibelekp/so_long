/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/15 19:57:45 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static t_map	map_p;

	return (&map_p);
}

int	check_args(int ac, char *av)
{
	size_t	i;

	if (ac != 2)
	{
		ft_printf("Error: wrong arguments. Usage: ./so_long <map.ber>\n");
		return (-1);
	}
	i = 0;
	i = (ft_strlen(av)) - 4;
	// ft_printf("&av[1][%d] = %s\n", i, &av[i]);
	if ((ft_strncmp(&av[i], ".ber", 4)) != 0)
	{
		ft_printf("Error: map must have the extention .ber\n");
		return (-1);
	}
	return (0);
}

void	map_matrix_rec(int nrow)
{
	char	*map_rows;

	map_rows = get_next_line(map()->fd);
	if (map_rows)
		map_matrix_rec(nrow + 1);
	else
	{
		map()->matrix = (char **)malloc(sizeof(char *) * (nrow + 1));
		map()->height = nrow;
	}
	map()->matrix[nrow] = map_rows;
}

// void	map_matrix(int map_fd)
// {
// 	int	rows;

// 	rows = 0;
// 	map()->matrix = (char **)malloc(sizeof(char *) * (6 + 1));
// 	// find number of rows
// 	while (1)
// 	{
// 		map()->matrix[rows] = get_next_line(map_fd);
// 		if (map()->matrix[rows] == NULL)
// 			break ;
// 		ft_printf("map.matrix[%d] %s", rows, map()->matrix[rows]);
// 		rows++;
// 	}
// 	close(map_fd);
// 	ft_printf("\nmap.matrix[%d] %s", rows, map()->matrix[rows]);
// 	map()->height = rows;
// 	ft_printf("\nmap.height = %d\n", map()->height);
// }

int	main(int ac, char **av)
{
	int	x;

	if (check_args(ac, av[1]) != 0)
	{
		ft_printf("Call exit_program.\n");
		return (-1);
	}
	map()->fd = open(av[1], O_RDONLY);
	if (map()->fd < 0)
		perror("Error: ");
	map()->height = 0;
	// map_matrix(map()->fd);
	map_matrix_rec(0);
	x = 0;
	while (map()->matrix[x])
	{
		ft_printf("map.matrix[%d] %s", x, map()->matrix[x]);
		x++;
	}
	ft_printf("\n%d\n", map()->height);
	return (0);
}
