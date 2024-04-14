/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:13:42 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 12:42:26 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Initialise the graphic display by the mlx (size - img+address)*/
void	init_img_mlx(t_data *data)
{
	data->mlx.img = mlx_new_image(data->mlx.mlx, WINDOW_W, WINDOW_H);
	data->mlx.addr = (int *)mlx_get_data_addr(data->mlx.img, \
		&data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	data->mlx.img_swap = mlx_new_image(data->mlx.mlx, \
		WINDOW_W, WINDOW_H);
	data->mlx.addr_swap = (int *)mlx_get_data_addr(data->mlx.img_swap,
			&data->mlx.bits_per_pixel, &data->mlx.line_length, \
			&data->mlx.endian);
}

void	init_img_minimap(t_data *data)
{
	int	i;

	i = 0;
	data->mlx.mini_wall = mlx_xpm_file_to_image(data->mlx.mlx,
			"./textures/mini/mini_wall.xpm", &i, &i);
	if (!data->mlx.mini_wall)
		exit_cub(data, "Mini map wall texture failed");
	data->mlx.mini_floor = mlx_xpm_file_to_image(data->mlx.mlx,
			"./textures/mini/mini_floor.xpm", &i, &i);
	if (!data->mlx.mini_floor)
		exit_cub(data, "Mini map floor texture failed");
}

/* Initialise the graphic textures displayed by the mlx (bits/pixels) */
void	init_addr_txtr(t_data *data)
{
	data->texture[0].addr = (int *)mlx_get_data_addr(data->texture[0].img,
			&data->texture[0].bits_per_pixel, &data->texture[0].line_length,
			&data->texture[0].endian);
	data->texture[1].addr = (int *)mlx_get_data_addr(data->texture[1].img,
			&data->texture[1].bits_per_pixel, &data->texture[1].line_length,
			&data->texture[1].endian);
	data->texture[2].addr = (int *)mlx_get_data_addr(data->texture[2].img,
			&data->texture[2].bits_per_pixel, &data->texture[2].line_length,
			&data->texture[2].endian);
	data->texture[3].addr = (int *)mlx_get_data_addr(data->texture[3].img,
			&data->texture[3].bits_per_pixel, &data->texture[3].line_length,
			&data->texture[3].endian);
}

/* Initialise the graphic textures displayed by the mlx (img/files.xpm) */
void	init_textures(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->parse.no, &data->texture[0].width, &data->texture[0].height);
	if (!data->texture[0].img)
		exit_cub(data, TXTR_FAILURE_NO);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->parse.so, &data->texture[1].width, &data->texture[1].height);
	if (!data->texture[1].img)
		exit_cub(data, TXTR_FAILURE_SO);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->parse.we, &data->texture[2].width, &data->texture[2].height);
	if (!data->texture[2].img)
		exit_cub(data, TXTR_FAILURE_WE);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx.mlx,
			data->parse.ea, &data->texture[3].width, &data->texture[3].height);
	if (!data->texture[3].img)
		exit_cub(data, TXTR_FAILURE_EA);
	init_img_minimap(data);
	init_addr_txtr(data);
}
