/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:35:41 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/17 22:50:17 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game = {0};

	if (argc != 2)
		return (ft_printf("Error\nInvalid number of arguments\n"), 1);
	if (!set_size(&game, argv[1]))
		return (ft_printf("Error\nInvalid map file\n"), 1);
	init_map(&game, argv[1]);
	check_map(&game);
	count_coins(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Error\nFailed to initialize mlx\n"),
			mlx_destroy_display(game.mlx), 1);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
			"So Long Awakening");
	if (!game.win)
		return (ft_printf("Error\nFailed to create window\n"),
			mlx_destroy_window(game.mlx, game.win),
			mlx_destroy_display(game.mlx), 1);
	init_images(&game);
	print_map(&game);
	display_strings(&game);
	mlx_key_hook(game.win, &handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
