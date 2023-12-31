/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:05 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/30 01:45:14 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mod_gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <time.h>
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

# define WHITE 0x00FFFFFF
# define BLACK 0xFF000000

# define IMG_WALL "images/water.xpm"
# define IMG_FLOOR "images/white_floor.xpm"
# define IMG_COIN "images/sushi20.xpm"
# define IMG_EXIT_CLOSED "images/box_closed.xpm"
# define IMG_EXIT_OPEN "images/box_open.xpm"

# define IMG_PLAYER_D1 "images/cat_front1.xpm"
# define IMG_PLAYER_D2 "images/cat_front2.xpm"
# define IMG_PLAYER_U1 "images/cat_back1.xpm"
# define IMG_PLAYER_U2 "images/cat_back2.xpm"
# define IMG_PLAYER_L1 "images/cat_left3.xpm"
# define IMG_PLAYER_L2 "images/cat_left4.xpm"
# define IMG_PLAYER_R1 "images/cat_right1.xpm"
# define IMG_PLAYER_R2 "images/cat_right2.xpm"

# define IMG_ENEMY_D1 "images/human_front1.xpm"
# define IMG_ENEMY_D2 "images/human_front2.xpm"

typedef enum e_direction
{
	D_UP,
	D_DOWN,
	D_LEFT,
	D_RIGHT,
}				t_direction;

typedef struct enemy
{
	int			x;
	int			y;
	int			frame;
	t_direction	dir;
}				t_enemy;

typedef struct map
{
	int			fd;
	char		**matrix;
	int			height;
	int			width;
	int			coins;
	int			valid_coins;
	int			valid_exit;
}				t_map;

typedef struct player
{
	int			x;
	int			y;
	int			steps;
	int			frame;
	int			time_frame;
	t_direction	dir;
}				t_player;

typedef struct graphics
{
	void		*mlx;
	void		*window;
	void		*wall;
	void		*background;
	void		*coin;
	void		*player[4][2];
	void		*exit[2];
	void		*enemy[2];
}				t_graphics;

// pointers
t_map			*map(void);
t_player		*player(void);
t_graphics		*graph(void);
t_enemy			*enemy(void);

int				check_args(int ac, char *av);
void			create_map_matrix(int nrow);
void			fatal_error(char *msg, int line);
void			check_path(int x, int y);
void			check_map_size(int y);
void			check_chars(char *row, int y, int x);
void			check_map(int y);

void			render_map(void);
void			move_player(int x_diff, int y_diff, t_direction dir);
int				handle_keys(int keycode);
void			display_steps(void);

void			start_game(t_graphics *temp);
int				exit_game(char *msg);
void			clean_mlx(void);
void			free_matrix(void);

void			display_matrix(int y);
void			init_vars(void);

void			*convert_img(char *img_path);
void			put_img(void *img_address, int x, int y);

void			move_enemy(int y_diff, int x_diff);

#endif