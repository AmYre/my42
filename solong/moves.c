/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:53:31 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/20 17:03:13 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	game->stored_moves = ft_itoa(game->player.moves);
	if (!game->stored_moves)
		return (ft_printf("Error\nFailed allocation memory\n"), close_game(game));
	mlx_string_put(game->mlx, game->win, 60, 25, 0x86C12E,
		game->stored_moves);
	free(game->stored_moves);
	game->player.moves++;
	game->stored_moves = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->win, 60, 25, 0xFFFFFF,
		game->stored_moves);
	free(game->stored_moves);
	ft_printf("moves : %d\n", game->player.moves);
}

void	move_up(t_game *game)
{
	if (game->map[(game->player.y / 64) - 1][game->player.x / 64] == '1')
		return ;
	if (game->map[(game->player.y / 64) - 1][game->player.x / 64] == 'E'
		&& game->player.coins == game->coins)
		close_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
		game->player.x, game->player.y);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_up.xpm", &game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
	game->player.y -= 64;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->player.x, game->player.y);
	if (game->map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->map[game->player.y / 64][game->player.x / 64] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->player.y / 64][game->player.x / 64 + 1] == '1')
		return ;
	if (game->map[game->player.y / 64][game->player.x / 64 + 1] == 'E'
		&& game->player.coins == game->coins)
		close_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
		game->player.x, game->player.y);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_right.xpm", &game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
	game->player.x += 64;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->player.x, game->player.y);
	if (game->map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->map[game->player.y / 64][game->player.x / 64] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player.y / 64][game->player.x / 64 - 1] == '1')
		return ;
	if (game->map[game->player.y / 64][game->player.x / 64 - 1] == 'E'
		&& game->player.coins == game->coins)
		close_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
		game->player.x, game->player.y);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player_left.xpm", &game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
	game->player.x -= 64;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->player.x, game->player.y);
	if (game->map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->map[game->player.y / 64][game->player.x / 64] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_down(t_game *game)
{
	if (game->map[(game->player.y / 64) + 1][game->player.x / 64] == '1')
		return ;
	if (game->map[(game->player.y / 64) + 1][game->player.x / 64] == 'E'
		&& game->player.coins == game->coins)
		close_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
		game->player.x, game->player.y);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load images\n"), close_game(game));
	game->player.y += 64;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->player.x, game->player.y);
	if (game->map[game->player.y / 64][game->player.x / 64] == 'C')
	{
		game->map[game->player.y / 64][game->player.x / 64] = '0';
		handle_coins(game);
	}
	print_moves(game);
}
