/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:05:43 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/06 15:25:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Get the path to the img (.xpm) we will need for the walls
(NO/SO/WE/EA) textures of the game */
char	*get_path_texture(char *line, t_data *data)
{
	int		x;
	int		y;
	int		spaces;
	char	*path;

	spaces = count_spaces(line, 2);
	path = (char *)malloc(sizeof(char) * (ft_strlen(line) - 2 - spaces) + 1);
	if (!path)
		free_data(data, "Memory Allocation failed", 1);
	x = 2;
	y = 0;
	while (line[x] != '\0')
	{
		while (line[x] == ' ')
			x++;
		path[y] = line[x];
		y++;
		x++;
	}
	path[y] = '\0';
	return (path);
}

void	check_id_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < find_map_start(data))
	{
		j = 0;
		while (data->parse.file[i][j] && data->parse.file[i][j] == ' ')
			j++;
		if (ft_strncmp(data->parse.file[i] + j, NORTH, 3) == 0)
			data->parse.no = get_path_texture(data->parse.file[i] + j, data);
		else if (ft_strncmp(data->parse.file[i] + j, SOUTH, 3) == 0)
			data->parse.so = get_path_texture(data->parse.file[i] + j, data);
		else if (ft_strncmp(data->parse.file[i] + j, WEST, 3) == 0)
			data->parse.we = get_path_texture(data->parse.file[i] + j, data);
		else if (ft_strncmp(data->parse.file[i] + j, EAST, 3) == 0)
			data->parse.ea = get_path_texture(data->parse.file[i] + j, data);
		else if (data->parse.file[i][j] == 'F'
			|| data->parse.file[i][j] == 'C')
			check_rgb(data, data->parse.file[i] + j);
		else
			free_data(data, WRONG_ID_TEXTURE, 1);
		i++;
	}
}

void	check_textures(t_data *data)
{
	if (!data->parse.no)
		free_data(data, "Header Error.", 1);
	if (!data->parse.so)
		free_data(data, "Header Error.", 1);
	if (!data->parse.we)
		free_data(data, "Header Error.", 1);
	if (!data->parse.ea)
		free_data(data, "Header Error.", 1);
}

/* Split then free the char *(data->parse.join) we got from 'get_file_content'.
The new char **(data->parse.file) is used to call functions checking
the identifiers and the map content */
void	check_content(t_data *data)
{
	int	x;
	int	save;

	data->parse.file = ft_split(data->parse.join, '\n');
	free(data->parse.join);
	x = find_map_start(data);
	if (!x || x > 6)
		free_data(data, "Map file not respecting rules.", 1);
	check_id_textures(data);
	check_textures(data);
	save = x;
	data->map_start = x;
	x = save;
	get_map_copy(data, save);
}

/* Get the file (.cub) content and copy it in a char *(data->parse.join)
we will split later */
int	get_file_content(t_data *data, int fd)
{
	int		x;
	char	*line;

	x = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free_data(data, EMPTY_FILE, 1);
	}
	while (line)
	{
		if (x != 0)
			line = get_next_line(fd);
		if (!line)
			break ;
		data->parse.join = ft_strjoin_gnl(data->parse.join, line);
		free(line);
		x++;
	}
	if (x < 5 || x > INT_MAX)
		free_data(data, ERR_FILE_SIZE, 1);
	return (0);
}
