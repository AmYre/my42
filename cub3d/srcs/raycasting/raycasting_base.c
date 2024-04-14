/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:25:23 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 13:20:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Calculation of the volumes of the walls columns (from the ceiling
to the floor) after being touch by rays */
void	volumes_walls(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = ((double)game->ray.map_x - game->ray.pos.x
				+ (1 - (double)game->ray.step_x) / 2) / game->ray.ray_dir.x;
	else
		game->ray.perp_wall_dist = ((double)game->ray.map_y - game->ray.pos.y
				+ (1 - (double)game->ray.step_y) / 2) / game->ray.ray_dir.y;
	game->ray.line_height = (int)(WINDOW_H / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + WINDOW_H / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + WINDOW_H / 2;
	if (game->ray.draw_end >= WINDOW_H || game->ray.draw_end < 0)
		game->ray.draw_end = WINDOW_H - 1;
}

/* Algorithm of raycasting - it generate the 3D representation.
Deals with the incrementation of rays transmitted
from the camera to the wall */
void	raycasting_alg(t_data *game)
{
	while (game->ray.hit == 0)
	{
		game->negatif = 0;
		if (game->ray.side_dist.x < game->ray.side_dist.y)
		{
			game->ray.side_dist.x += game->ray.delta_dist.x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist.y += game->ray.delta_dist.y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_x < 0 || game->ray.map_y < 0)
		{
			game->negatif = 1;
			break ;
		}
		if (game->parse.map_copy[game->ray.map_x][game->ray.map_y] == '1')
			game->ray.hit = 1;
	}
	volumes_walls(game);
}

/* Part of the algorithm needed to raycast proprely.
Deals with calculation of the side distance from 'x' (column) perspective */
void	get_sidedist_x(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.ray_dir.x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist.x = (game->ray.pos.x - game->ray.map_x)
			* game->ray.delta_dist.x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist.x = (game->ray.map_x + 1.0 - game->ray.pos.x)
			* game->ray.delta_dist.x;
	}
}

/* Part of the algorithm needed to raycast proprely.
Deals with calculation of the side distance from 'y' (lines) perspective */
void	get_sidedist_y(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.ray_dir.y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist.y = (game->ray.pos.y - game->ray.map_y)
			* game->ray.delta_dist.y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist.y = (game->ray.map_y + 1.0 - game->ray.pos.y)
			* game->ray.delta_dist.y;
	}
}

/* Main loop for raycasting (rendering, update display, update moves) */
int	raycasting_loop(t_data *data)
{
	int	x;

	x = 0;
	while (x < WINDOW_W)
	{
		restart_init(data, x);
		get_sidedist_x(data);
		get_sidedist_y(data);
		raycasting_alg(data);
		display_volumes(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx,
		data->mlx.mlx_win, data->mlx.img, 0, 0);
	forward_or_backward(data);
	left_or_right(data);
	camera_rotate_right(data);
	camera_rotate_left(data);
	ray_swap_img(data);
	print_mini_map(data);
	mlx_rectangle_put(data->mlx.mlx, data->mlx.mlx_win,
		data->ray.pos.y * 8, data->ray.pos.x * 8);
	draw_fov(data);
	return (0);
}
