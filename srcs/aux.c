/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:54:43 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:13:14 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	*graph(void)
{
	static t_graphics	g;

	return (&g);
}

t_player	*player(void)
{
	static t_player	p;

	return (&p);
}

t_map	*map(void)
{
	static t_map	map_p;

	return (&map_p);
}

t_enemy	*enemy(void)
{
	static t_enemy	n;

	return (&n);
}
