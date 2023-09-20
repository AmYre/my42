/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:01:46 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/20 16:52:34 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_game *game)
{
	mlx_hook(game->win, 17, 0, close_window, game);
	if (keycode == XK_Escape)
		close_game(game);
	if (keycode == XK_Up || keycode == KEY_W)
		move_up(game);
	if (keycode == XK_Right || keycode == KEY_D)
		move_right(game);
	if (keycode == XK_Left || keycode == KEY_A)
		move_left(game);
	if (keycode == XK_Down || keycode == KEY_S)
		move_down(game);
	return (0);
}

void	display_strings(t_game *game)
{
	char	*coins;

	coins = ft_itoa(game->coins);
	if (!coins)
		return (ft_printf("Error\nFailed to allocate memory\n"), close_game(game));
	game->title_count = "moves : ";
	game->title_coins = "coins : ";
	mlx_string_put(game->mlx, game->win, 10, 25, 0xFFFFFF, game->title_count);
	mlx_string_put(game->mlx, game->win, 10, 50, 0xFFFFFF, game->title_coins);
	mlx_string_put(game->mlx, game->win, 80, 50, 0xFFFFFF, "/");
	mlx_string_put(game->mlx, game->win, 90, 50, 0xFFFFFF, coins);
	free(coins);
}

int	close_window(t_game *game)
{
	close_game(game);
	return (0);
}

void	free_images(t_game *game)
{
	if (game->img.bg)
		mlx_destroy_image(game->mlx, game->img.bg);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
}

void	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if(game->map[i])
			free(game->map[i]);
		if(game->flood_map[i])
			free(game->flood_map[i]);
		i++;
	}
	free(game->map);
	free(game->flood_map);
	free_images(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
