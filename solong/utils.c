/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:22:07 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/20 17:03:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	game->img.bg = mlx_xpm_file_to_image(game->mlx, "./assets/bg.xpm",
			&(game->img.width), &(game->img.height));
	if (!game->img.bg)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
	mlx_put_image_to_window(game->mlx, game->win, game->img.bg, 0, 0);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&(game->img.width), &(game->img.height));
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "./assets/coin.xpm",
			&(game->img.width), &(game->img.height));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&(game->img.width), &(game->img.height));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&(game->img.width), &(game->img.height));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&(game->img.width), &(game->img.height));
	if (!game->player.img || !game->img.coin || !game->img.exit
		|| !game->img.floor || !game->img.wall)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
}

void	handle_coins(t_game *game)
{
	game->stored_coins = ft_itoa(game->player.coins);
	if (!game->stored_coins)
		return (ft_printf("Error\nFailed allocation memory\n"), close_game(game));
	mlx_string_put(game->mlx, game->win, 60, 50, 0x86C12E,
		game->stored_coins);
	free(game->stored_coins);
	game->player.coins++;
	game->stored_coins = ft_itoa(game->player.coins);
	if (!game->stored_coins)
		return (ft_printf("Error\nFailed allocation memory\n"), close_game(game));
	mlx_string_put(game->mlx, game->win, 60, 50, 0xFFFFFF,
		game->stored_coins);
	free(game->stored_coins);
	if (game->player.coins == game->coins)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->exit_x * 64, game->exit_y * 64);
	}
}

void	free_maps(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		free(game->flood_map[i]);
		i++;
	}
	free(game->map);
	free(game->flood_map);
}
