/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:16 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/08 12:18:34 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mlx_rectangle_put(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + 8)
	{
		j = y;
		while (j < y + 8)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *data, int end_x, int end_y)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = end_x - (data->ray.pos.y + 0.5) * 8;
	delta_y = end_y - (data->ray.pos.x + 0.5) * 8;
	pixel_x = (data->ray.pos.y + 0.5) * 8;
	pixel_y = (data->ray.pos.x + 0.5) * 8;
	pixels = 3;
	while (pixels)
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win,
			pixel_x, pixel_y, 0x00FF0000);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	draw_fov(t_data *data)
{
	double	player_angle;
	double	angle;
	double	end_x;
	double	end_y;

	player_angle = atan2(data->ray.dir.x, data->ray.dir.y);
	angle = player_angle - 0.52;
	while (angle <= player_angle + 0.52)
	{
		end_x = (data->ray.pos.y + 0.5) * 8 + 20 * cos(angle);
		end_y = (data->ray.pos.x + 0.5) * 8 + 20 * sin(angle);
		draw_line(data, (int)end_x, (int)end_y);
		angle += 0.03;
	}
}

void	print_mini_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->parse.map_copy[i])
	{
		j = 0;
		while (data->parse.map_copy[i][j])
		{
			if (data->parse.map_copy[i][j] == '0'
				|| data->parse.map_copy[i][j] == 'N'
				|| data->parse.map_copy[i][j] == 'S'
				|| data->parse.map_copy[i][j] == 'W'
				|| data->parse.map_copy[i][j] == 'E')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->mlx.mini_floor, j * 8, i * 8);
			else
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->mlx.mini_wall, j * 8, i * 8);
			j++;
		}
		i++;
	}
}
