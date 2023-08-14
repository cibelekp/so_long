/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:58:55 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/14 14:03:53 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_map(int fd)
// {
// }

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		map_file;
	char	*str;

	map_file = open(av[1], O_RDONLY);
	if (map_file < 0)
		perror("Error: ");
	ft_printf("Map fd = %d\n", map_file);
	str = get_next_line(map_file);
	ft_printf("%s\n", str);
	if (map_file != -1)
	{
		close(map_file);
		ft_printf("Closed map fd.\n");
	}
	return (0);
}
