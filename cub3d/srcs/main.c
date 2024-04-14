/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:06:29 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 13:52:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cross_exit(t_data *data)
{
	exit_cub(data, END_GAME);
	return (0);
}

int	start_game(t_data *data)
{
	mlx_hook(data->mlx.mlx_win, 5, 1L << 3, &release_mouse, data);
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, &game_keys, data);
	mlx_mouse_hook(data->mlx.mlx_win, &game_mouse, data);
	mlx_hook(data->mlx.mlx_win, 17, 1L << 17, &cross_exit, data);
	mlx_loop_hook(data->mlx.mlx, &raycasting_loop, data);
	mlx_hook(data->mlx.mlx_win, 3, 1L << 1, &release_keys, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (ac != 2 || !data)
		return (free(data),
			printf("Error\nCub3D only accepts one argument\n"), 1);
	parsing(data, av[1]);
	if (ft_init_game(data))
		start_game(data);
	exit_cub(data, END_GAME);
	return (0);
}
