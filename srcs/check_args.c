/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:22:48 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:22:52 by ckojima-         ###   ########.fr       */
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
