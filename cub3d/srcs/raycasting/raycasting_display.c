/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:52:00 by ryounssi          #+#    #+#             */
/*   Updated: 2024/03/31 11:52:08 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Initialise textures shown base on rays and players position*/
void	init_game_textures(t_data *game)
{
	if (game->ray.side == 0 && game->ray.ray_dir.x < 0)
		game->t.texdir = 0;
	if (game->ray.side == 0 && game->ray.ray_dir.x >= 0)
		game->t.texdir = 1;
	if (game->ray.side == 1 && game->ray.ray_dir.y < 0)
		game->t.texdir = 2;
	if (game->ray.side == 1 && game->ray.ray_dir.y >= 0)
		game->t.texdir = 3;
	if (game->ray.side == 0)
		game->t.wall_x = game->ray.pos.y + game->ray.perp_wall_dist
			* game->ray.ray_dir.y;
	else
		game->t.wall_x = game->ray.pos.x + game->ray.perp_wall_dist
			* game->ray.ray_dir.x;
	game->t.wall_x -= floor(game->t.wall_x);
}

/* Get the right texture of walls base on rays and players position */
void	display_game_texture(t_data *game, int x, int y)
{
	y = game->ray.draw_start - 1;
	init_game_textures(game);
	game->t.step = 1.0 * game->texture[0].height / game->ray.line_height;
	game->t.tex_x = (int)(game->t.wall_x
			* (double)game->texture[game->t.texdir].width);
	if (game->ray.side == 0 && game->ray.ray_dir.x > 0)
		game->t.tex_x = game->texture[game->t.texdir].width - game->t.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir.x < 0)
		game->t.tex_x = game->texture[game->t.texdir].width - game->t.tex_x - 1;
	game->t.tex_pos = (game->ray.draw_start - WINDOW_H / 2
			+ game->ray.line_height / 2) * game->t.step;
	while (++y <= game->ray.draw_end)
	{
		game->t.tex_y = (int)game->t.tex_pos
			& (game->texture[game->t.texdir].height - 1);
		game->t.tex_pos += game->t.step;
		if (y < WINDOW_H && x < WINDOW_W)
			game->mlx.addr[y * game->mlx.line_length / 4 + x]
				= game->texture[game->t.texdir].addr[game->t.tex_y
				* game->texture[game->t.texdir].line_length / 4
				+ game->t.tex_x];
	}
}

/* Get RBG codes needed to coloring the floor and ceiling */
static int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/* Draw the volumes of the walls from the ceiling to the floor */
int	display_volumes(t_data *game, int x)
{
	int	y;
	int	z;

	z = -1;
	if (game->negatif == 1)
		return (0);
	game->ceiling = rgb_to_int(game->rgb.rgb_c[0], game->rgb.rgb_c[1], \
						game->rgb.rgb_c[2]);
	game->floor = rgb_to_int(game->rgb.rgb_f[0], game->rgb.rgb_f[1], \
						game->rgb.rgb_f[2]);
	game->ray.draw_end = WINDOW_H - game->ray.draw_start;
	y = game->ray.draw_end;
	while (++z < game->ray.draw_start)
		game->mlx.addr[z * game->mlx.line_length / 4 + x] = game->ceiling;
	if (z <= game->ray.draw_end)
		display_game_texture(game, x, z);
	z = y;
	while (++z < WINDOW_H)
		game->mlx.addr[z * game->mlx.line_length / 4 + x] = game->floor;
	return (0);
}
