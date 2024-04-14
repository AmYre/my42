/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:08:25 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 12:42:51 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Initialise the window to display the game */
void	init_window(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		free_data(data, FAILURE_MLX_INIT, 1);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, WINDOW_W, \
						WINDOW_H, "Cub3D");
	if (!data->mlx.mlx_win)
		free_data(data, FAILURE_MLX_WINDOW, 1);
}

/* Initialise the variables used for rayscasting and
getting the player movements in game */
void	init_moves_ray(t_data *data)
{
	data->mlx.move.forward = 0;
	data->mlx.move.backward = 0;
	data->mlx.move.left = 0;
	data->mlx.move.right = 0;
	data->mlx.move.rot_r = 0;
	data->mlx.move.rot_l = 0;
	data->ray.pos.x = (double)data->player.x + 0.5;
	data->ray.pos.y = (double)data->player.y + 0.5;
	data->ray.dir.x = 0;
	data->ray.dir.y = 0;
	data->ray.plane.x = 0;
	data->ray.plane.y = 0;
	data->negatif = 0;
	data->floor = -1;
	data->ceiling = -1;
}

/* Initialise the variables used for the game's display */
void	init_var_game(t_data *data)
{
	init_moves_ray(data);
	data->mlx.mlx = NULL;
	data->mlx.mlx_win = NULL;
	data->mlx.img = NULL;
	data->mlx.img_swap = NULL;
	data->mlx.mini_wall = NULL;
	data->mlx.mini_floor = NULL;
	data->mlx.addr = NULL;
	data->mlx.addr_swap = NULL;
	data->mlx.bits_per_pixel = 0;
	data->mlx.line_length = 0;
	data->mlx.endian = 0;
	data->texture[0].img = NULL;
	data->texture[1].img = NULL;
	data->texture[2].img = NULL;
	data->texture[3].img = NULL;
	data->texture[0].addr = NULL;
	data->texture[1].addr = NULL;
	data->texture[2].addr = NULL;
	data->texture[3].addr = NULL;
}

/* Assign the direction of the player's view
at game's launch */
void	assign_direction(t_data *game)
{
	if (game->player.pos_n == 1)
		game->ray.dir.x = -1;
	if (game->player.pos_s == 1)
		game->ray.dir.x = 1;
	if (game->player.pos_e == 1)
		game->ray.dir.y = 1;
	if (game->player.pos_w == 1)
		game->ray.dir.y = -1;
	if (game->player.pos_n == 1)
		game->ray.plane.y = 0.66;
	if (game->player.pos_s == 1)
		game->ray.plane.y = -0.66;
	if (game->player.pos_e == 1)
		game->ray.plane.x = 0.66;
	if (game->player.pos_w == 1)
		game->ray.plane.x = -0.66;
}

/* Calls all initialisatins functions needed for
displaying the game */
int	ft_init_game(t_data *data)
{
	check_characters(data, data->map_start);
	check_walls(data, 0);
	init_var_game(data);
	assign_direction(data);
	init_window(data);
	init_textures(data);
	if (data->map_start != 6)
		exit_cub(data, "Floor and Ceiling RGB values needed");
	init_img_mlx(data);
	return (1);
}
