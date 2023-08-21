/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/21 19:08:15 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}

t_map	*map(void)
{
	static t_map	map_p;

	return (&map_p);
}

int	check_args(int ac, char *av)
{
	size_t	i;

	if (ac != 2)
		fatal_error("Error: wrong arguments. Usage: ./so_long <map.ber>\n", 0);
	i = 0;
	i = (ft_strlen(av)) - 4;
	// ft_printf("&av[1][%d] = %s\n", i, &av[i]);
	if ((ft_strncmp(&av[i], ".ber", 4)) != 0)
		fatal_error("Error: map must have the extention .ber\n", 0);
	return (0);
}

void	map_matrix_rec(int nrow)
{
	char	*map_rows;

	map_rows = mod_gnl(map()->fd);
	if (map_rows)
		map_matrix_rec(nrow + 1);
	else
	{
		map()->matrix = (char **)malloc(sizeof(char *) * (nrow + 1));
		map()->height = nrow;
	}
	map()->matrix[nrow] = map_rows;
}

int	main(int ac, char **av)
{
	int	y;

	check_args(ac, av[1]);
	map()->fd = open(av[1], O_RDONLY);
	if (map()->fd < 0)
		perror("Error: ");
	map()->height = 0;
	map_matrix_rec(0);
	y = 0;
	while (map()->matrix[y])
	{
		if (map()->matrix[y][0] == '\n')
			ft_printf("map.matrix[%d] %s", y, map()->matrix[y]);
		else
			ft_printf("map.matrix[%d] %s\n", y, map()->matrix[y]);
		y++;
	}
	ft_printf("map.matrix[%d] %s", y, map()->matrix[y]);
	ft_printf("\nheight: %d\n", map()->height);
	check_map();
	ft_printf("Checked path:\n");
	y = 0;
	while (map()->matrix[y])
	{
		if (y > map()->height)
			ft_printf("map.matrix[%d] %s", y, map()->matrix[y]);
		else
			ft_printf("map.matrix[%d] %s\n", y, map()->matrix[y]);
		y++;
	}
	ft_printf("map.matrix[%d] %s", y, map()->matrix[y]);
	return (0);
}
