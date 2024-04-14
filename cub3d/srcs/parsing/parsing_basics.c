/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:05:24 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/06 15:42:41 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Initialise variables for parsing and the player position on the map */
void	parsing_file(t_data *data, char *path_map)
{
	data->fd = open(path_map, O_RDONLY);
	if (data->fd < 0 || (read (data->fd, 0, 0) < 0))
	{
		close(data->fd);
		free_data(data, NO_FILE, 1);
	}
	if (get_file_content(data, data->fd) == 0)
		check_content(data);
}

/* Initialise variables for parsing and the player position on the map */
void	init_data(t_data *data)
{
	data->parse.file = NULL;
	data->parse.map_copy = NULL;
	data->parse.join = NULL;
	data->parse.no = NULL;
	data->parse.so = NULL;
	data->parse.we = NULL;
	data->parse.ea = NULL;
	data->parse.player_count = 0;
	data->map_start = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->player.pos_n = 0;
	data->player.pos_s = 0;
	data->player.pos_w = 0;
	data->player.pos_e = 0;
}

int	check_filename(t_data *data, char *path_map)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(path_map);
	while (path_map[len] != '.')
		len--;
	if (path_map[len] == '.')
		len++;
	i = len + 1;
	j = i + 1;
	if (path_map[len] != 'c' || path_map[i] != 'u' || path_map[j] != 'b'
		|| path_map[j + 1] != '\0')
		exit_free(data, CUB_FILE, 1);
	return (0);
}

int	parsing(t_data *data, char *path_map)
{
	check_filename(data, path_map);
	init_data(data);
	parsing_file(data, path_map);
	return (0);
}
