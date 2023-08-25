/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:54:43 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/25 16:10:16 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_graphics	*graph(void)
{
	static t_graphics	graphics;

	return (&graphics);
}

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
