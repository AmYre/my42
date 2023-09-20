/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:11:23 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/19 01:36:55 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_result(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->flood_map[j])
	{
		while (game->flood_map[j][i])
		{
			if (game->flood_map[j][i] == 'E')
				return (ft_printf("Error\nExit not reachable\n"),
					free_maps(game), exit(1));
			if (game->flood_map[j][i] == 'C')
				return (ft_printf("Error\nCoins not reachable\n"),
					free_maps(game), exit(1));
			i++;
		}
		j++;
		i = 0;
	}
}

int	flood_fill(int x, int y, t_game *game)
{
	if (game->flood_map[x][y] == '1' || game->flood_map[x][y] == 'V')
		return (0);
	game->flood_map[x][y] = 'V';
	if (flood_fill(x - 1, y, game) || flood_fill(x + 1, y, game)
		|| flood_fill(x, y - 1, game) || flood_fill(x, y + 1, game))
		return (1);
	return (0);
}

void	check_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->flood_map[i])
	{
		while (game->flood_map[i][j])
		{
			if (game->flood_map[i][j] == 'P')
			{
				game->pos_x = i;
				game->pos_y = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	flood_fill(game->pos_x, game->pos_y, game);
	path_result(game);
}
