/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:05 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/25 21:46:02 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./mod_gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

# define PLAYER p
# define WALL 1
# define COIN c
# define EXIT e
# define FLOOR o

# define WHITE 0x00FFFFFF
# define BLACK 0xFF000000

# define PLAYER_IMG "images/player.xpm"
# define WALL_IMG "images/water2.xpm"
# define COIN_IMG "images/collectible.xpm"
# define EXIT_IMG "images/exit.xpm"
# define FLOOR_IMG "images/grass.xpm"

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
	int		steps;
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
}			t_graphics;

// pointers
t_map		*map(void);
t_player	*player(void);
t_graphics	*graph(void);

int			check_args(int ac, char *av);
void		create_map_matrix(int nrow);
void		fatal_error(char *msg, int line);
void		check_path(int x, int y);
void		check_map_size(int y);
void		check_chars(char *row, int y, int x);
void		check_map(int y);

int			render_map(void);
void		move_player(int x_diff, int y_diff);
int			handle_keys(int keycode);
void		display_steps(void);

void		start_game(t_graphics *temp);
int			exit_game(void);
void		clean_mlx(void);
void		free_matrix(void);

void		display_matrix(int y);
void		init_vars(void);

void		*convert_img(char *img_path);
void		put_img(void *img_address, int x, int y);

#endif