/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:05:55 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/08 10:57:38 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen_double(char **str)
{
	int	x;

	x = 0;
	while (str[x] != NULL)
		x++;
	return (x);
}

/* Check if there is only one player on the map */
int	ft_player_count(char c, t_data *data)
{
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
	{
		data->parse.player_count++;
		return (data->parse.player_count);
	}
	else
		return (-1);
}

/* Check the range of each RBG number/code */
int	ft_check_range(t_data *data, char id)
{
	if (id == 'f')
	{
		if (data->rgb.rgb_f[0] < 0 || data->rgb.rgb_f[0] > 255
			|| data->rgb.rgb_f[1] < 0 || data->rgb.rgb_f[1] > 255
			|| data->rgb.rgb_f[2] < 0 || data->rgb.rgb_f[2] > 255)
			return (0);
	}
	if (id == 'c')
	{
		if (data->rgb.rgb_c[0] < 0 || data->rgb.rgb_c[0] > 255
			|| data->rgb.rgb_c[1] < 0 || data->rgb.rgb_c[1] > 255
			|| data->rgb.rgb_c[2] < 0 || data->rgb.rgb_c[2] > 255)
			return (0);
	}
	return (1);
}

int	find_map_start(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->parse.file[x] != NULL)
	{
		y = 0;
		while (data->parse.file[x][y] != '\0')
		{
			if (data->parse.file[x][y] == 'N' || data->parse.file[x][y] == 'S'
				|| data->parse.file[x][y] == 'W'
				|| data->parse.file[x][y] == 'E'
				|| data->parse.file[x][y] == 'F'
				|| data->parse.file[x][y] == 'C')
				break ;
			else if (data->parse.file[x][y] == '1')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

/* Check which ID is contained in the line and get its informations
and send it to 'new_line' */
char	*check_id_line(char *line, int *id)
{
	int		x;
	char	*new_line;

	x = 0;
	*id = 0;
	new_line = NULL;
	while (line[x] != '\0')
	{
		if (line[x] == 'N' || line[x] == 'S' || line[x] == 'W'
			|| line[x] == 'E' || line[x] == 'F' || line[x] == 'C')
		{
			*id = line[x];
			new_line = ft_substr(line, x, strlen(line));
			return (new_line);
		}
		x++;
	}
	free(new_line);
	return (NULL);
}
