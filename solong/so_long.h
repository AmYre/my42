/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:22:50 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/20 16:39:18 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libs/gnl/get_next_line.h"
# include "./libs/libft/libft.h"
# include "./libs/mlx/mlx.h"
# include "./libs/printf/ft_printf.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_W 122
# define KEY_A 113
# define KEY_S 115
# define KEY_D 100

typedef struct s_img
{
	void		*bg;
	void		*coin;
	void		*wall;
	void		*exit;
	void		*floor;
	int			width;
	int			height;
}				t_img;

typedef struct s_player
{
	void		*img;
	int			x;
	int			y;
	int			moves;
	int			coins;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**flood_map;
	int			width;
	int			height;
	int			coins;
	int			is_coin;
	int			is_exit;
	int			is_player;
	int			pos_x;
	int			pos_y;
	int			exit_x;
	int			exit_y;
	char		*title_count;
	char		*title_coins;
	char		*stored_coins;
	char		*stored_moves;
	t_img		img;
	t_player	player;
}				t_game;

int				set_size(t_game *game, char *file);
void			init_map(t_game *game, char *file);
int				print_map(t_game *game);
void			init_images(t_game *game);
void			display_strings(t_game *game);

int				handle_input(int keycode, t_game *game);
void			move_up(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_down(t_game *game);
void			print_moves(t_game *game);

void			count_coins(t_game *game);
void			handle_coins(t_game *game);

void			check_map(t_game *game);
void			check_chars(t_game *game);
void			check_boundaries(t_game *game);
void			check_player(t_game *game);
void			check_coins(t_game *game);
void			check_exit(t_game *game);
void			check_file(char *file, int fd);
void			check_path(t_game *game);
int				flood_fill(int x, int y, t_game *game);
void			path_result(t_game *game);

void			free_maps(t_game *game);
int				close_window(t_game *game);
void			close_game(t_game *game);

#endif
