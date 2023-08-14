/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/14 15:35:42 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_map(int fd)
// {
// }

int	main(int ac, char **av)
{
	int		map_file;
	char	*temp;
	char	**map;
	int		i;

	(void)ac;
	(void)av;
	map_file = open(av[1], O_RDONLY);
	if (map_file < 0)
		perror("Error: ");
	ft_printf("Map fd = %d\n", map_file);
	i = 0;
	map = NULL;
	temp = NULL;
	while ((temp = get_next_line(map_file)) != NULL)
	{
		ft_printf("%s", temp);
		map[i] = temp;
		ft_printf("%s", map[i]);
		temp = NULL;
		i++;
	}
	// map[i] = NULL;
	// i = 0;
	// while (map[i] != NULL)
	// {
	// 	ft_printf("%s", map[i]);
	// 	i++;
	// }
	if (map_file != -1)
	{
		close(map_file);
		ft_printf("\nClosed map fd.\n");
	}
	return (0);
}
