/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:05 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/21 12:32:57 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct map
{
	int		fd;
	char	**matrix;
	int		height;
	int		length;
	int		exit_x;
	int		exit_y;
	int		collectable;

}			t_map;

typedef struct player
{
	int		x;
	int		y;
}			t_player;

// pointers
t_map		*map(void);
t_player	*player(void);

void		check_map(void);

#endif