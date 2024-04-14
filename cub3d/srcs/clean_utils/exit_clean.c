/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:06:14 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 12:42:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_imgs(t_data *data)
{
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	if (data->mlx.img_swap)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img_swap);
	if (data->mlx.mini_wall)
		mlx_destroy_image(data->mlx.mlx, data->mlx.mini_wall);
	if (data->mlx.mini_floor)
		mlx_destroy_image(data->mlx.mlx, data->mlx.mini_floor);
}

/* Clean all mlx graphic tools used and call 'free_data'
to clean the rest of the program */
void	exit_cub(t_data *data, char *msg)
{
	int	i;

	i = 0;
	if (data->fd > 0)
		close(data->fd);
	if (strcmp(msg, END_GAME) != 0)
		printf("Error\n%s\n", msg);
	else
		printf("%s%s\t%s\n", "\033[21m", "\033[36m", msg);
	while (i < 4)
	{
		if (data->texture[i].img)
			mlx_destroy_image(data->mlx.mlx, data->texture[i].img);
		i++;
	}
	free_imgs(data);
	if (data->mlx.mlx_win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	if (data->mlx.mlx)
		mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	free_data(data, NULL, 0);
}

/* To free char **(tab) */
void	free_double_tab(char **tofree)
{
	int	x;

	x = 0;
	while (tofree[x])
	{
		free(tofree[x]);
		x++;
	}
	free(tofree);
}

/* Clean all variable of data that were allocated */
void	free_data(t_data *data, char *msg, int x)
{
	if (data->fd > 0)
		close(data->fd);
	if (data->parse.file)
		free_double_tab(data->parse.file);
	if (data->parse.map_copy)
		free_double_tab(data->parse.map_copy);
	if (data->parse.no)
		free(data->parse.no);
	if (data->parse.so)
		free(data->parse.so);
	if (data->parse.we)
		free(data->parse.we);
	if (data->parse.ea)
		free(data->parse.ea);
	exit_free(data, msg, x);
}

/* Printf 'Error' if needed and exit the program */
int	exit_free(t_data *data, char *msg, int x)
{
	free(data);
	if (x == 1)
		printf("Error\n%s\n", msg);
	exit(x);
}
