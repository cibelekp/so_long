/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:05 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/22 19:40:37 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./mod_gnl/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

typedef struct map
{
	int		fd;
	char	**matrix;
	int		height;
	int		width;
	int		coins;
	int		valid_coins;
	int		valid_exit;

}			t_map;

typedef struct player
{
	int		x;
	int		y;
}			t_player;

typedef struct graphics
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*background;
	void	*coin;
	void	*player;
	void	*exit;

}	t_graphics;

// pointers
t_map		*map(void);
t_player	*player(void);
t_graphics	*graph(void);

void		check_map(void);
void		fatal_error(char *msg, int line);
void		start_window(void);


#endif