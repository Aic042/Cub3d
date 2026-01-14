/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:27 by sbolivar          #+#    #+#             */
/*   Updated: 2026/01/14 15:38:04 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	comp_temp(char *temp, int fd)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (temp)
	{
		if (temp[0] == '\n')
			error++;
		while (temp[i] == ' ' || temp[i] == '\t')
		{
			i++;
			if (temp[0] == '\n')
				error++;
		}
		free(temp);
		temp = get_next_line(fd);
	}
	return (error);
}

int	comp_paths(t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	while (game->paths[i])
	{
		fd = open(game->paths[i], O_RDONLY);
		if (fd == -1)
			return (1);
		i++;
	}
	return (0);
}

int	comp_map(t_game *game)
{
	int		fd;
	char	*temp;
	int		i;

	i = 0;
	fd = open(game->select_map, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), fd);
	temp = get_next_line(fd);
	if (comp_temp(temp, fd))
		return (1);
	return (0);
}
