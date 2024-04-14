/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:01:30 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/15 00:45:25 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Assign '1' according to the player letter (N/S/W/E) */
void	player_dir(t_data *data, int x, int y)
{
	if (data->parse.map_copy[x][y] == 'N')
		data->player.pos_n = 1;
	if (data->parse.map_copy[x][y] == 'S')
		data->player.pos_s = 1;
	if (data->parse.map_copy[x][y] == 'W')
		data->player.pos_w = 1;
	if (data->parse.map_copy[x][y] == 'E')
		data->player.pos_e = 1;
}

/* Get the player position (x, y) on the map */
void	get_player_pos(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'W' || map[x][y] == 'E')
			{
				data->player.x = x;
				data->player.y = y;
				break ;
			}
			y++;
		}
		x++;
	}
	player_dir(data, data->player.x, data->player.y);
}

/* Get a specific copy of the map (data->parse.map_copy) */
void	get_map_copy(t_data *data, int x)
{
	char	*tmp_copy;

	tmp_copy = NULL;
	while (data->parse.file[x] != NULL)
	{
		tmp_copy = ft_strjoin_gnl(tmp_copy, data->parse.file[x]);
		tmp_copy = ft_strjoin_gnl(tmp_copy, "\n");
		x++;
	}
	data->parse.map_copy = ft_split(tmp_copy, '\n');
	get_player_pos(data, data->parse.map_copy);
	free(tmp_copy);
}

void	check_walls(t_data *data, int x)
{
	int	y;

	while (data->parse.map_copy[x] != NULL)
	{
		y = 0;
		while (data->parse.map_copy[x][y] != '\0')
		{
			if (data->parse.map_copy[x][y] != '1'
				&& data->parse.map_copy[x][y] != ' ')
			{
				if (x == 0 || x == ft_strlen_double(data->parse.map_copy) - 1
					|| y == 0 || data->parse.map_copy[x - 1][y] == ' '
					|| data->parse.map_copy[x][y + 1] == ' '
					|| data->parse.map_copy[x][y - 1] == ' '
					|| data->parse.map_copy[x][y + 1] == '\0'
					|| y > ((int)ft_strlen(data->parse.map_copy[x - 1]) - 1)
					|| y > ((int)ft_strlen(data->parse.map_copy[x + 1]) - 1))
					free_data(data, WRONG_WALLS, 1);
			}
			y++;
		}
		x++;
	}
}

/* Check if the map includes only 3 types of characters
(1 - for walls | 0 - for emptyspace | N/S/W/E - for only one player) */
void	check_characters(t_data *data, int x)
{
	int	y;

	while (data->parse.file[x] != NULL)
	{
		y = 0;
		while (data->parse.file[x][y] != '\0' && data->parse.file[x][y] != '\n')
		{
			if (data->parse.file[x][y] == ' ')
			{
				while (data->parse.file[x][y] == ' ')
					y++;
			}
			else if (data->parse.file[x][y] == '1'
					|| data->parse.file[x][y] == '0')
				y++;
			else if (ft_player_count(data->parse.file[x][y], data) != (-1))
				y++;
			else
				free_data(data, WRONG_MAP_CHAR, 1);
		}
		x++;
	}
	if (data->parse.player_count != 1)
		free_data(data, WRONG_PLAYER, 1);
}
