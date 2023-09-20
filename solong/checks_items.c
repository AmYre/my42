/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:39:07 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/19 01:29:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_game *game)
{
	if (game->is_player < 1)
		return (ft_printf("Error\nAt least one player is needed\n"),
			free_maps(game), exit(1));
	if (game->is_player > 1)
		return (ft_printf("Error\nOnly one player is needed\n"),
			free_maps(game), exit(1));
}

void	check_exit(t_game *game)
{
	if (game->is_exit < 1)
		return (ft_printf("Error\nAt least one exit is needed\n"),
			free_maps(game), exit(1));
	if (game->is_exit > 1)
		return (ft_printf("Error\nOnly one exit is needed\n"),
			free_maps(game), exit(1));
}

void	check_coins(t_game *game)
{
	if (game->is_coin < 1)
		return (ft_printf("Error\nAt least one coin needed\n"),
			free_maps(game), exit(1));
}

void	check_file(char *file, int fd)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b'
		|| file[i - 4] != '.')
		return (ft_printf("Error\nFile is not a .ber\n"), close(fd), exit(1));
}
