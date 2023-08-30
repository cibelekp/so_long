/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:11:56 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(void)
{
	player()->steps = 0;
	map()->fd = -1;
	graph()->wall = NULL;
	player()->dir = D_DOWN;
	enemy()->dir = D_DOWN;
}

void	create_map_matrix(int nrow)
{
	char	*map_rows;

	map_rows = mod_gnl(map()->fd);
	if (map_rows)
		create_map_matrix(nrow + 1);
	else
	{
		map()->matrix = (char **)malloc(sizeof(char *) * (nrow + 1));
		map()->height = nrow;
	}
	map()->matrix[nrow] = map_rows;
}

int	main(int ac, char **av)
{
	check_args(ac, av[1]);
	create_map_matrix(0);
	check_map(0);
	init_vars();
	start_game(graph());
	exit_game("Exiting game\n");
	return (0);
}
