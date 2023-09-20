/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:58:32 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/20 16:55:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_coins(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				game->coins++;
			i++;
		}
		j++;
		i = 0;
	}
}

int	set_size(t_game *game, char *file)
{
	char	*line;
	int		fd;

	game->width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, &line, 0) < 0)
		return (0);
	check_file(file, fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->height == 0)
			game->width = ft_strlen(line) - 1;
		game->height++;
		free(line);
	}
	close(fd);
	return (1);
}

void	init_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	game->map = ft_calloc(sizeof(char *), game->height + 1);
	if (!game->map)
		return (ft_printf("Error\nFailed to allocate memory\n"), exit(1));
	game->flood_map = ft_calloc(sizeof(char *), game->height + 1);
	if (!game->flood_map)
		return (free(game->map), ft_printf("Error\nFailed to allocate memory"), exit(1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			return (ft_printf("Error\nFailed to allocate memory"), close_game(game), exit(1));
		game->flood_map[i] = ft_strdup(line);
		if (!game->flood_map[i])
			return (ft_printf("Error\nFailed to allocate memory"), close_game(game), exit(1));
		free(line);
		i++;
	}
	game->map[i] = NULL;
	game->flood_map[i] = NULL;
	close(fd);
}

void	print_image(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, i * 64, j
			* 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coin, i * 64, j
			* 64);
	if (c == 'P')
	{
		game->player.x = i * 64;
		game->player.y = j * 64;
		mlx_put_image_to_window(game->mlx, game->win, game->player.img,
			game->player.x, game->player.y);
	}
	if (c == 'E')
	{
		game->exit_x = i;
		game->exit_y = j;
	}
}

int	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == '1')
				print_image(game, '1', i, j);
			if (game->map[j][i] == 'C')
				print_image(game, 'C', i, j);
			if (game->map[j][i] == 'E')
				print_image(game, 'E', i, j);
			if (game->map[j][i] == 'P')
				print_image(game, 'P', i, j);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}
