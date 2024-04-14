/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_keys_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:05:37 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/15 00:41:34 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Swap images and display while raycasting and player's move */
void	ray_swap_img(t_data *game)
{
	void	*tmp;

	tmp = game->mlx.img;
	game->mlx.img = game->mlx.img_swap;
	game->mlx.img_swap = tmp;
	tmp = game->mlx.addr;
	game->mlx.addr = game->mlx.addr_swap;
	game->mlx.addr_swap = tmp;
}

/* Identification of keycodes(released) for the player's
moves in the game */
int	release_keys(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->mlx.move.forward = 0;
	else if (keycode == KEY_S)
		data->mlx.move.backward = 0;
	else if (keycode == KEY_A)
		data->mlx.move.left = 0;
	else if (keycode == KEY_D)
		data->mlx.move.right = 0;
	else if (keycode == KEY_LEFT)
		data->mlx.move.rot_l = 0;
	else if (keycode == KEY_RIGHT)
		data->mlx.move.rot_r = 0;
	return (1);
}

/* Identification of keycodes(press) for the player's
moves in the game */
int	game_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_cub(data, END_GAME);
	else if (keycode == KEY_W)
		data->mlx.move.forward = 1;
	else if (keycode == KEY_S)
		data->mlx.move.backward = 1;
	else if (keycode == KEY_A)
		data->mlx.move.left = 1;
	else if (keycode == KEY_D)
		data->mlx.move.right = 1;
	else if (keycode == KEY_LEFT)
		data->mlx.move.rot_l = 1;
	else if (keycode == KEY_RIGHT)
		data->mlx.move.rot_r = 1;
	return (1);
}

int	game_mouse(int button, int x, int y, t_data *data)
{
	int	center_x;
	int	distance_from_center_x;

	(void)button;
	(void)y;
	center_x = WINDOW_W / 2;
	distance_from_center_x = x - center_x;
	data->mlx.move.rot_l = 0;
	data->mlx.move.rot_r = 0;
	if (distance_from_center_x < 0)
		data->mlx.move.rot_l = 1;
	else if (distance_from_center_x > 0)
		data->mlx.move.rot_r = 1;
	return (0);
}

int	release_mouse(int button, int x, int y, t_data *data)
{
	int	center_x;
	int	distance_from_center_x;

	(void)button;
	(void)y;
	center_x = WINDOW_W / 2;
	distance_from_center_x = x - center_x;
	if (distance_from_center_x < 0)
		data->mlx.move.rot_l = 0;
	else if (distance_from_center_x > 0)
		data->mlx.move.rot_r = 0;
	return (0);
}
