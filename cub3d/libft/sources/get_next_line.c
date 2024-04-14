/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:21:30 by ryounssi          #+#    #+#             */
/*   Updated: 2022/06/21 22:21:39 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *res)
{
	char	*line;
	int		idx;

	idx = 0;
	if (!res)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen_gnl(res) + 1);
	if (!line)
		return (NULL);
	while (res[idx])
	{
		line[idx] = res[idx];
		idx++;
		if (res[idx - 1] == '\n')
			break ;
	}
	line[idx] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_save_static(char *res)
{
	char	*save;
	int		idx;
	int		i;

	i = 0;
	idx = 0;
	while (res[idx] && res[idx] != '\n')
		idx++;
	if (res[idx])
		idx++;
	else
		return (free(res), NULL);
	save = malloc(sizeof(char) * (ft_strlen_gnl(res + idx) + 1));
	if (save == NULL)
	{
		free (res);
		return (NULL);
	}
	while (res[idx])
		save[i++] = res[idx++];
	save[i] = '\0';
	free(res);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	char		*temp;
	int			rx;

	rx = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (rx != 0 && (ft_strchr(buffer, '\n') == NULL))
	{
		rx = read(fd, temp, BUFFER_SIZE);
		if (rx < 0)
			return (NULL);
		temp[rx] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
	}
	free(temp);
	line = ft_get_line(buffer);
	buffer = ft_save_static(buffer);
	return (line);
}
