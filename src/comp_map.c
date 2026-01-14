/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:27 by sbolivar          #+#    #+#             */
/*   Updated: 2026/01/14 14:03:19 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	comp_map(t_game *game)
{
	int		fd;
	char	*temp;
	int		i;
	int		error;

	error = 0;
	i = 0;
	fd = open(game->select_map, O_RDONLY);
	if (fd == -1)
		return (perror("Error al abrir el archivo"), fd);
	temp = get_next_line(fd);
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
	if (error > 0)
		return (1);
	return (0);
}
