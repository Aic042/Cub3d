/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:22:49 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/05 11:31:06 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int	ft_validate_file(char	*map_path)
{
	char	*file;

	file = ft_strrchr(map_path, '.');
	if (file == NULL || ft_strcmp(file, ".cub") != 0)
	{
		ft_printf("Error de mapa!");
		return (0);
	}
	return (1);
}
//By me ^^

int		get_y(int size_y)
{
	int	fd;
	char	*temp;

	fd = open("src/read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (0);
	}
	while ((temp = get_next_line(fd)) != NULL)
	{
		size_y++;
		free(temp);
	}
	close(fd);
	return (size_y);
}

void	get_sizes(t_game *game)
{
	int	fd;
	char	*temp;

	fd = open("src/read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	while ((temp = get_next_line(fd)))
	{
		if (game->size_x < (int)ft_strlen(temp))
			game->size_x = ft_strlen(temp);
		free(temp);
	}
	close(fd);
	game->size_y = get_y(game->size_y);
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

void	get_map_utils(t_game  *game)
{
	int	fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open("src/read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return ;
	}
	game->map = ft_calloc(sizeof(char *), game->size_y + 1);
	while ((temp = get_next_line(fd)) != NULL)
	{
		game->map[i] = ft_calloc(sizeof(char *), game->size_x + 1);
		game->map[i] = give_map_line(game->map[i], temp);
		free(temp);
		i++;
	}
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
	get_sizes(game);
	get_map_utils(game);
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
	if (!map_parse(game) && player == 1)
		return (game->map);
	return (NULL);
}
