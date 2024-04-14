/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:02:18 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 13:50:57 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                              INCLUDES		                              */
/* ************************************************************************** */

# include <stdio.h>  /* for printf, perror */
# include <string.h> /* for strerror */
# include <unistd.h> /* for write, close, read, exit */
# include <stdlib.h> /* for malloc, free */
# include <fcntl.h> /* for open */
# include <math.h> /* for math library functions */
# include <limits.h> /* for limits of variables */

# include "../libft/includes/get_next_line.h" /* for GNL functions*/
# include "../libft/includes/libft.h" /* for libft functions */
# include "../minilibx-linux/mlx.h" /* for MLX functions */
# include "struct.h" /* for structures of the project */

/* ************************************************************************** */
/*                              DEFINES			                              */
/* ************************************************************************** */

/* MSG BASIC ERRORS */
# define CUB_FILE "Wrong file extention (.cub)"
# define XPM_FILE "Wrong file extention for textures (.xpm)"
# define NO_FILE "File not found"
# define ERR_FILE_SIZE "Invalid size of file - 5 to INT_MAX lines allowed"
# define EMPTY_FILE "File is Empty"

/* CARDINALS */
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "
# define WRONG_ID_TEXTURE "Check ID for Cub3D's textures\
 : north (NO), south (SO), west(WE), east(EA)."

/* RGB (FLOOR & CEILING) */
# define FLOOR "F"
# define CEILING "C"
# define WRONG_ID_RGB "Check ID for Cub3D's RGG\
 : FLOOR (F) & CEILING (C)."
# define WRONG_RGB_FORMAT "Check Cub3D's RGB format\
 : R*, G*, B* [*number with range between 0 to 255]."

/* MAP CHARACTERS & WALLS */
# define WRONG_MAP_CHAR "Check Cub3D's map allowed characters\
 : 1(walls), 0(empty spaces), N/S/W/E(player)."
# define WRONG_PLAYER "Only one player permitted."
# define WRONG_WALLS "Each blocks of Cub3D's map should be\
 surrounded by walls (character '1')."

/* MLX */
# define FAILURE_MLX_INIT "Function mlx_init() FAILED."
# define FAILURE_MLX_WINDOW "Function mlx_new_window() FAILED."

/* DISPLAY */
# define WINDOW_H 800
# define WINDOW_W 1280

/* TEXTURES & IMAGES */
# define TXTR_FAILURE_NO "Texture not found (NO)."
# define TXTR_FAILURE_SO "Texture not found (SO)."
# define TXTR_FAILURE_WE "Texture not found (WE)."
# define TXTR_FAILURE_EA "Texture not found (EA)."

/* KEYCODES */
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

/* END OF GAME */
# define END_GAME	"CONGRATS : YOU ARE OUT THE MAZE !"

/* TESTING */
# define TEST_OK "ALL GOOD IT SEEMS"

/* ************************************************************************** */
/*                              MAIN	 		                              */
/* ************************************************************************** */

int		main(int ac, char **av);

/* ************************************************************************** */
/*                              PARSING 		                              */
/* ************************************************************************** */

/* basics */
int		parsing(t_data *data, char *av);
int		check_filename(t_data *data, char *name);
void	init_data(t_data *data);
void	parsing_file(t_data *data, char *av);
int		get_file_content(t_data *data, int fd);
void	print_mini_map(t_data *data);

/* file content + map */
void	check_content(t_data *data);
void	check_id_textures(t_data *data);
char	*get_path_texture(char *line, t_data *data);
int		find_map_start(t_data *data);
char	*check_id_line(char *line, int *id);
void	check_rgb(t_data *data, char *line);
void	parse_rbg_line(t_data *data, char *line, char id);
int		check_rbg_num(t_data *data, char *line, char id);
void	assign_num(t_data *data, char **num, char id);
void	check_map_content(t_data *data);
void	check_characters(t_data *data, int x);
void	check_walls(t_data *data, int x);
void	get_map_copy(t_data *data, int x);
void	get_player_pos(t_data *data, char **map);
void	player_dir(t_data *data, int x, int y);
void	draw_fov(t_data *data);
void	draw_line(t_data *data, int end_x, int end_y);

/* utils (parsing) */
int		ft_check_range(t_data *data, char id);
int		ft_close_spaces(char *tocheck, int idx);
int		ft_player_count(char c, t_data *data);
int		count_spaces(char *line, int i);
int		ft_strlen_double(char **str);
char	*trim_spaces(char *line);
int		is_rgb_format(t_data *data, char *line);

/* ************************************************************************** */
/*                              INITIALISATION                 				  */
/* ************************************************************************** */

int		ft_init_game(t_data *data);
void	print_mini_map(t_data *data);
void	mlx_rectangle_put(void *mlx_ptr, void *win_ptr, int x, int y);
void	init_var_game(t_data *data);
void	init_window(t_data *data);
void	init_textures(t_data *data);
void	init_addr_txtr(t_data *data);
void	init_img_mlx(t_data *data);
int		start_game(t_data *data);
void	restart_init(t_data *game, int x);
void	rest_of_init(t_data *game);

/* ************************************************************************** */
/*                              MOVES & RAYCASTING                     	      */
/* ************************************************************************** */

/* basics && init */
void	init_moves_ray(t_data *data);
int		game_keys(int keycode, t_data *data);
int		release_keys(int keycode, t_data *data);
int		release_mouse(int button, int x, int y, t_data *data);
int		game_mouse(int button, int x, int y, t_data *data);

/* raycasting */
int		raycasting_loop(t_data *data);
void	get_sidedist_x(t_data *game);
void	get_sidedist_y(t_data *game);
void	raycasting_alg(t_data *game);
void	volumes_walls(t_data *game);
int		display_volumes(t_data *game, int x);
void	display_game_texture(t_data *game, int x, int y);
void	init_game_textures(t_data *game);

/* moves */
void	forward_or_backward(t_data *d);
void	left_or_right(t_data *data);
void	camera_rotate_right(t_data *game);
void	camera_rotate_left(t_data *game);
void	ray_swap_img(t_data *game);

/* ************************************************************************** */
/*                              CLEANING 		                              */
/* ************************************************************************** */

int		exit_free(t_data *data, char *msg, int x);
void	free_data(t_data *data, char *msg, int x);
void	free_double_tab(char **tofree);
void	exit_cub(t_data *data, char *msg);
int		cross_exit(t_data *data);

#endif