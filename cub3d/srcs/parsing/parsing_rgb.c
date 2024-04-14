/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:11:31 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/06 12:00:55 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* Assign the right number/code to each color (Red, Blue, Green)
for the floor (F) ofr the ceiling (C) */
void	assign_num(t_data *data, char **num, char id)
{
	if (id == 'f')
	{
		data->rgb.rgb_f[0] = ft_atoi(num[0]);
		data->rgb.rgb_f[1] = ft_atoi(num[1]);
		data->rgb.rgb_f[2] = ft_atoi(num[2]);
	}
	else
	{
		data->rgb.rgb_c[0] = ft_atoi(num[0]);
		data->rgb.rgb_c[1] = ft_atoi(num[1]);
		data->rgb.rgb_c[2] = ft_atoi(num[2]);
	}
	free_double_tab(num);
}

/* Check if the RBG code valid (number and range) */
int	check_rbg_num(t_data *data, char *line, char id)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = ft_split(line, ',');
	while (tmp[count] != NULL)
		count++;
	if (count != 3)
	{
		free_double_tab(tmp);
		return (1);
	}
	assign_num(data, tmp, id);
	if (ft_check_range(data, id) != 1)
		return (1);
	return (0);
}

/* Check if the RBG code valid (format of the line) */
void	parse_rbg_line(t_data *data, char *line, char id)
{
	char	*trimed_line;
	char	*new_line;
	int		comma;
	int		i;
	int		x;

	i = 0;
	x = 2;
	comma = 0;
	trimed_line = NULL;
	new_line = NULL;
	new_line = malloc(sizeof(char) * ft_strlen(line));
	while (line[x] != '\0')
		new_line[i++] = line[x++];
	new_line[i] = '\0';
	comma = is_rgb_format(data, new_line);
	trimed_line = trim_spaces(new_line);
	free(new_line);
	if (comma != 2 || ft_strlen(trimed_line) > 11
		|| check_rbg_num(data, trimed_line, id) == 1)
	{
		free(trimed_line);
		free_data(data, WRONG_RGB_FORMAT, 1);
	}
	free(trimed_line);
}

/* Check if the RBG code valid (identifiers and format) */
void	check_rgb(t_data *data, char *line)
{
	if (ft_strncmp(line, FLOOR, 1) == 0)
		parse_rbg_line(data, line, 'f');
	else if (ft_strncmp(line, CEILING, 1) == 0)
		parse_rbg_line(data, line, 'c');
	else
		free_data(data, WRONG_ID_RGB, 1);
}
