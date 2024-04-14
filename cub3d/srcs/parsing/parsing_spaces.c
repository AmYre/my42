/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:50:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/06 12:04:51 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*trim_spaces(char *line)
{
	int		i;
	int		x;
	int		spaces;
	char	*trimed_line;

	spaces = count_spaces(line, 0);
	trimed_line = malloc(((sizeof(char) * strlen(line)) + 1) - spaces);
	x = 0;
	i = 0;
	while (line[x])
	{
		if (line[x] != ' ' && line[x] != '\t' && line[x] != '\n'
			&& line[x] != '\v' && line[x] != '\f' && line[x] != '\r')
		{
			trimed_line[i] = line[x];
			i++;
		}
		x++;
	}
	trimed_line[i] = '\0';
	return (trimed_line);
}

int	count_spaces(char *line, int i)
{
	int	spaces;

	spaces = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
			spaces++;
		i++;
	}
	return (spaces);
}

int	is_rgb_format(t_data *data, char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != ' ')
		{
			free(line);
			free_data(data, WRONG_RGB_FORMAT, 1);
		}
		if (line[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}
