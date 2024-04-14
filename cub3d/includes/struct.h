/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:04:54 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 12:43:02 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
/* ************************************************************************** */
/*                              DATA_STRUCT		                              */
/* ************************************************************************** */

typedef struct s_texture
{
	int			texdir;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_texture;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_ray
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
	double		camera_x;
	int			map_x;
	int			map_y;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	int			x;
	int			texture;
}				t_ray;

typedef struct s_moves
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			rot_l;
	int			rot_r;
}	t_moves;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		endian;
	int		start;
	void	*img;
	void	*mini_wall;
	void	*mini_floor;
	void	*img_swap;
	int		*addr;
	int		*addr_swap;
	int		bits_per_pixel;
	int		line_length;
	t_moves	move;
}	t_mlx;

typedef struct s_player
{
	int		x;
	int		y;
	int		pos_n;
	int		pos_s;
	int		pos_w;
	int		pos_e;
}	t_player;

typedef struct s_rgb
{
	int	rgb_f[3];
	int	rgb_c[3];
}	t_rgb;

typedef struct s_parse
{
	char	**file;
	char	**map_copy;
	char	*join;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	int		player_count;
}	t_parse;

typedef struct s_data
{
	t_parse		parse;
	int 		fd;
	t_rgb		rgb;
	t_mlx		mlx;
	int			map_start;
	t_mlx		texture[4];
	t_texture	t;
	t_ray		ray;
	t_player	player;
	int			negatif;
	int			ceiling;
	int			floor;
}	t_data;

#endif
