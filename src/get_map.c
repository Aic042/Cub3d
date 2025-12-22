/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:22:49 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/18 14:11:10 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_y(int size_y, char *map)
{
	int		fd;
	char	*temp;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (0);
	}
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		size_y++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (size_y - 6);
}

void	get_sizes(t_game *game)
{
	int		fd;
	char	*temp;

	fd = open(game->select_map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	temp = get_next_line(fd);
	while (temp)
	{
		if (game->size_x < (int)ft_strlen(temp))
			game->size_x = ft_strlen(temp);
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	game->size_y = get_y(game->size_y, game->select_map);
	return ;
}

char	*give_map_line(char *map, char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		map[i] = temp[i];
		i++;
	}
	return (map);
}

void	get_map_utils(t_game *game)
{
	int	fd;

	fd = open(game->select_map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	game->map = ft_calloc(sizeof(char *), game->size_y + 1);
	game->inf = ft_calloc(sizeof(char *), 7);
	get_text(fd, game->inf, game, 0);
	get_text(fd, game->map, game, 1);
	close(fd);
	return ;
}

char	**get_map(t_game *game)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	game->select_map = ft_strjoin("maps/", game->select_map);
	get_sizes(game);
	get_map_utils(game);
	get_paths(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			x++;
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
			|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
				player++;
		}
		y++;
	}
	if (!map_parse(game, 0, 0) && player == 1)
		return (game->map);
	return (NULL);
}
