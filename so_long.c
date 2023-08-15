/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/15 18:43:25 by ckojima-         ###   ########.fr       */
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

void	map_matrix(int map_fd)
{
	char	*map_row;
	int		rows;

	map_row = NULL;
	rows = 0;
	map()->matrix = (char **)malloc(sizeof(char *) * (rows + 1));
	while ((map_row = get_next_line(map_fd)) != NULL)
	{
		map()->matrix[rows] = map_row;
		ft_printf("map.matrix[%d] %s", rows, map()->matrix[rows]);
		rows++;
	}
	map()->matrix[rows] = NULL;
	ft_printf("\nmap.matrix[%d] %s", rows, map()->matrix[rows]);
	map()->height = rows;
	ft_printf("\nmap.height = %d\n", map()->height);
}

int	main(int ac, char **av)
{
	int	map_fd;
	int	x;

	if (check_args(ac, av[1]) != 0)
	{
		ft_printf("Call exit_program.\n");
		return (-1);
	}
	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 0)
		perror("Error: ");
	map()->height = 0;
	// CREATE MATRIX
	map_matrix(map_fd);
	// LATER: CLEANUP FUNCTION	ft_printf("\nmap.height = %d", map()->height);
	x = 0;
	while (map()->height >= 0)
	{
		ft_printf("map.matrix[%d] %s\n", x, map()->matrix[x]);
		x++;
		map()->height -= 1;
	}
	{
		close(map_fd);
		// ft_printf("\nClosed map fd.\n");
	}
	return (0);
}
