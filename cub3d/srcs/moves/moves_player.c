/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 10:54:39 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/06 19:00:19 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Vectorial rotation of player's view (right) by pressing (left arrow)key */
void	camera_rotate_left(t_data *game)
{
	double	oldplanex;
	double	olddirx;

	if (game->negatif == 1)
		return ;
	oldplanex = game->ray.plane.x;
	olddirx = game->ray.dir.x;
	if (game->mlx.move.rot_l == 1)
	{
		game->ray.dir.x = game->ray.dir.x * cos(game->ray.rot_speed / 10)
			- game->ray.dir.y * sin(game->ray.rot_speed / 10);
		game->ray.dir.y = olddirx * sin(game->ray.rot_speed / 10)
			+ game->ray.dir.y * cos(game->ray.rot_speed / 10);
		game->ray.plane.x = game->ray.plane.x * cos(game->ray.rot_speed / 10)
			- game->ray.plane.y * sin(game->ray.rot_speed / 10);
		game->ray.plane.y = oldplanex * sin(game->ray.rot_speed / 10)
			+ game->ray.plane.y * cos(game->ray.rot_speed / 10);
	}
}

/* Vectorial rotation of player's view (right) by pressing (right arrow)key */
void	camera_rotate_right(t_data *game)
{
	double	oldplanex;
	double	olddirx;

	if (game->negatif == 1)
		return ;
	oldplanex = game->ray.plane.x;
	olddirx = game->ray.dir.x;
	if (game->mlx.move.rot_r == 1)
	{
		game->ray.dir.x = game->ray.dir.x * cos(-game->ray.rot_speed / 10)
			- game->ray.dir.y * sin(-game->ray.rot_speed / 10);
		game->ray.dir.y = olddirx * sin(-game->ray.rot_speed / 10)
			+ game->ray.dir.y * cos(-game->ray.rot_speed / 10);
		game->ray.plane.x = game->ray.plane.x * cos(-game->ray.rot_speed / 10)
			- game->ray.plane.y * sin(-game->ray.rot_speed / 10);
		game->ray.plane.y = oldplanex * sin(-game->ray.rot_speed / 10)
			+ game->ray.plane.y * cos(-game->ray.rot_speed / 10);
	}
}

/* Moves of the player (right or left) by pressing (D)key or (A)key */
void	left_or_right(t_data *data)
{
	if (data->negatif == 1)
		return ;
	if (data->mlx.move.right == 1)
	{
		if (data->parse.map_copy[(int)(data->ray.pos.x + (data->ray.dir.y
					* data->ray.move_speed))][(int)data->ray.pos.y] != '1')
			data->ray.pos.x += data->ray.dir.y * data->ray.move_speed * 0.09;
		if (data->parse.map_copy[(int)data->ray.pos.x][(int)(data->ray.pos.y
			- (data->ray.dir.x * data->ray.move_speed))] != '1')
			data->ray.pos.y -= data->ray.dir.x * data->ray.move_speed * 0.09;
	}
	else if (data->mlx.move.left == 1)
	{
		if (data->parse.map_copy[(int)(data->ray.pos.x - (data->ray.dir.y
					* data->ray.move_speed))][(int)data->ray.pos.y] != '1')
			data->ray.pos.x -= data->ray.dir.y * data->ray.move_speed * 0.09;
		if (data->parse.map_copy[(int)data->ray.pos.x][(int)(data->ray.pos.y
			+ (data->ray.dir.x * data->ray.move_speed))] != '1')
			data->ray.pos.y += data->ray.dir.x * data->ray.move_speed * 0.09;
	}
}

/* Moves of the player (forward or backward) by pressing (W)key or (S)key */
void	forward_or_backward(t_data *d)
{
	if (d->negatif == 1)
		return ;
	if (d->mlx.move.forward == 1)
	{
		if (d->parse.map_copy[(int)(d->ray.pos.x + (d->ray.dir.x * \
				d->ray.move_speed))][(int)d->ray.pos.y] != '1')
			d->ray.pos.x += d->ray.dir.x * d->ray.move_speed * 0.09;
		if (d->parse.map_copy[(int)d->ray.pos.x][(int)(d->ray.pos.y \
				+ (d->ray.dir.y * d->ray.move_speed))] != '1')
			d->ray.pos.y += d->ray.dir.y * d->ray.move_speed * 0.09;
	}
	else if (d->mlx.move.backward == 1)
	{
		if (d->parse.map_copy[(int)(d->ray.pos.x - (d->ray.dir.x \
				* d->ray.move_speed))][(int)d->ray.pos.y] != '1')
			d->ray.pos.x -= d->ray.dir.x * d->ray.move_speed * 0.09;
		if (d->parse.map_copy[(int)d->ray.pos.x][(int)(d->ray.pos.y - \
				(d->ray.dir.y * d->ray.move_speed))] != '1')
			d->ray.pos.y -= d->ray.dir.y * d->ray.move_speed * 0.09;
	}
}
