/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_layout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:50:51 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/19 01:33:53 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] != '1' && game->map[j][i] != 'C'
				&& game->map[j][i] != 'E' && game->map[j][i]
				!= 'P' && game->map[j][i] != '0')
				return (ft_printf("Error\nUnmatched chars"), free_maps(game),
					exit(1));
			i++;
		}
		j++;
		i = 0;
	}
}

void	check_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->height < 3 || game->width < 3 || game->height > 15
		|| game->width > 30)
		return (ft_printf("Error\nSize not adapted\n"),
			free_maps(game), exit(1));
}

void	check_square(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		if (game->width != (int)ft_strlen(game->map[j]))
			return (ft_printf("Error\nMap is not a rectangle\n"),
				free_maps(game), exit(1));
		j++;
	}
}

void	check_boundaries(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'E')
				game->is_exit++;
			if (game->map[j][i] == 'P')
				game->is_player++;
			if (game->map[j][i] == 'C')
				game->is_coin++;
			if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1'
				||
				game->map[j][0] != '1' || game->map[j][game->width - 1] != '1')
				return (ft_printf("Error\nNo boundaries\n"),
					free_maps(game), exit(1));
			i++;
		}
		j++;
		i = 0;
	}
}

void	check_map(t_game *game)
{
	game->is_exit = 0;
	game->is_player = 0;
	game->is_coin = 0;
	check_chars(game);
	check_square(game);
	check_size(game);
	check_boundaries(game);
	check_player(game);
	check_exit(game);
	check_coins(game);
	check_path(game);
}
