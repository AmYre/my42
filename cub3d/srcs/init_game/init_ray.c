/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:53:21 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/03 18:07:57 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Initialise the player's view and the speed of movement and rotation */
void	restart_init(t_data *game, int x)
{
	game->ray.hit = 0;
	game->ray.perp_wall_dist = 0;
	game->ray.camera_x = 2 * x / (double)WINDOW_W - 1;
	game->ray.ray_dir.x = game->ray.dir.x + game->ray.plane.x
		* game->ray.camera_x;
	game->ray.ray_dir.y = game->ray.dir.y + game->ray.plane.y
		* game->ray.camera_x;
	game->ray.map_x = (int)game->ray.pos.x;
	game->ray.map_y = (int)game->ray.pos.y;
	game->ray.move_speed = 0.5;
	game->ray.rot_speed = 0.099 * 1.8;
	rest_of_init(game);
}

/* (Re)start calculation for rayscating and display :
- (new) start of the ray(casting)
- conact (hit) of ray with the wall
- x and y axis */
void	rest_of_init(t_data *game)
{
	if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.x = 0;
	else if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.x = 1;
	else
		game->ray.delta_dist.x = sqrt(1 + (game->ray.ray_dir.y * \
		game->ray.ray_dir.y) / (game->ray.ray_dir.x * game->ray.ray_dir.x));
	if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.y = 0;
	else if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.y = 1;
	else
		game->ray.delta_dist.y = sqrt(1 + (game->ray.ray_dir.x * \
		game->ray.ray_dir.x) / (game->ray.ray_dir.y * game->ray.ray_dir.y));
}
