/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:57:37 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/12 23:12:30 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*gnl(int fd)
{
	char	*line;
	char	*tmp;
	int		bytes_read;

	line = malloc(sizeof(char) * (1024 + 1));
	if (!line)
		return (NULL);
	bytes_read = read(fd, line, 1024);
	if (bytes_read < 0)
		return (free(line), NULL);
	line[bytes_read] = '\0';
	tmp = ft_strdup(line);
	if (!tmp)
		return (free(line), NULL);
	free(line);
	return (tmp);
}

void	here_doc(t_pipex *pipex, t_fds *fds)
{
	char	*line;

	line = NULL;
	fds->here_doc = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds->here_doc < 0)
		return (perror("Open here_doc failed"), exit(1));
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = gnl(STDIN_FILENO);
		if (!line)
			return (ft_printf("Gnl failed\n"), exit(1));
		if (ft_strncmp(line, pipex->argv[2], ft_strlen(pipex->argv[2])) == 0)
		{
			free(line);
			break ;
		}
		write(fds->here_doc, line, ft_strlen(line));
		free(line);
	}
	close(fds->here_doc);
}
