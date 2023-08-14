/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/14 16:45:06 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int ac, char **av)
{
	int		map_file;
	char	*temp;
	char	**map;
	int		i;

	if (check_args(ac, av[1]) != 0)
	{
		ft_printf("Exiting program.\n");
		return (-1);
	}
	map_file = open(av[1], O_RDONLY);
	if (map_file < 0)
		perror("Error: ");
	i = 0;
	map = NULL;
	temp = NULL;
	// CHECK MAP RULES BEFORE ALLOCATING MEMORY?
	// CREATE MATRIX
	while ((temp = get_next_line(map_file)) != NULL)
	{
		ft_printf("%s", temp);
		// map[i] = temp;
		// ft_printf("%s", map[i]);
		temp = NULL;
		// i++;
	}
	// map[i] = NULL;
	// i = 0;
	// while (map[i] != NULL)
	// {
	// 	ft_printf("%s", map[i]);
	// 	i++;
	// }
	
	// LATER: CLEANUP FUNCTION
	if (map_file != -1)
	{
		close(map_file);
		ft_printf("\nClosed map fd.\n");
	}
	return (0);
}
