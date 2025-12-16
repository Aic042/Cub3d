/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:12:20 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/09 15:40:27 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_strings(char **av)
{
	int		i;

	i = 0;
	while (av[i] != NULL)
		i++;
	return (i);
}

int	player_case(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (map[y][x - 1] == '0' || map[y][x - 1] == '1')
		i++;
	if (map[y][x + 1] == '0' || map[y][x + 1] == '1')
		i++;
	if (map[y - 1][x] == '0' || map[y - 1][x] == '1')
		i++;
	if (map[y + 1][x] == '0' || map[y + 1][x] == '1')
		i++;
	if (i == 4)
		return (0);
	return (1);
}

int	zero_case(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (map[y][x - 1] == '0' || map[y][x - 1] == '1' || map[y][x - 1] == 'N'
			|| map[y][x - 1] == 'S' || map[y][x - 1] == 'E'
			|| map[y][x - 1] == 'W')
		i++;
	if (map[y][x + 1] == '0' || map[y][x + 1] == '1' || map[y][x + 1] == 'N'
			|| map[y][x + 1] == 'S' || map[y][x + 1] == 'E'
			|| map[y][x + 1] == 'W')
		i++;
	if (map[y - 1][x] == '0' || map[y - 1][x] == '1' || map[y - 1][x] == 'N'
			|| map[y - 1][x] == 'S' || map[y - 1][x] == 'E'
			|| map[y - 1][x] == 'W')
		i++;
	if (map[y + 1][x] == '0' || map[y + 1][x] == '1' || map[y + 1][x] == 'N'
			|| map[y + 1][x] == 'S' || map[y + 1][x] == 'E'
			|| map[y + 1][x] == 'W')
		i++;
	if (i == 4)
		return (0);
	return (1);
}

int	wall_case(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (map[y][x - 1] == '0' || map[y][x - 1] == '1' || map[y][x - 1] == 'N' ||
		map[y][x - 1] == 'S' || map[y][x - 1] == 'E' || map[y][x - 1] == '\n' ||
		map[y][x - 1] == 'W' || map[y][x - 1] == ' ' || map[y][x - 1] == '\t')
		i++;
	if (map[y][x + 1] == '0' || map[y][x + 1] == '1' || map[y][x + 1] == 'N' ||
		map[y][x + 1] == 'S' || map[y][x + 1] == 'E' || map[y][x + 1] == '\n' ||
		map[y][x + 1] == 'W' || map[y][x + 1] == ' ' || map[y][x + 1] == '\t' ||
		map[y][x + 1] == '\0')
		i++;
	if (map[y - 1][x] == '0' || map[y - 1][x] == '1' || map[y - 1][x] == 'N' ||
		map[y - 1][x] == 'S' || map[y - 1][x] == 'E' || map[y - 1][x] == '\n' ||
		map[y - 1][x] == 'W' || map[y - 1][x] == ' ' || map[y - 1][x] == '\t' ||
		map[y - 1][x] == '\0')
		i++;
	if (map[y + 1][x] == '0' || map[y + 1][x] == '1' || map[y + 1][x] == 'N' ||
		map[y + 1][x] == 'S' || map[y + 1][x] == 'E' || map[y + 1][x] == '\n' ||
		map[y + 1][x] == 'W' || map[y + 1][x] == ' ' || map[y + 1][x] == '\t' ||
		map[y + 1][x] == '\0')
		i++;
	if (i == 4)
		return (0);
	return (1);
}

int	space_case(int x, int y, char **map)
{
	int	i;

	i = 0;
	if (map[y][x - 1] == '0' || map[y][x - 1] == '1' || map[y][x - 1] == '\n' ||
		map[y][x - 1] == ' ' || map[y][x - 1] == '\t' || map[y][x - 1] == '\0')
		i++;
	if (map[y][x + 1] == '0' || map[y][x + 1] == '1' || map[y][x + 1] == '\n' ||
		map[y][x + 1] == ' ' || map[y][x + 1] == '\t' || map[y][x + 1] == '\0')
		i++;
	if (map[y - 1][x] == '0' || map[y - 1][x] == '1' || map[y - 1][x] == '\n' ||
		map[y - 1][x] == ' ' || map[y - 1][x] == '\t' || map[y - 1][x] == '\0')
		i++;
	if (map[y + 1][x] == '0' || map[y + 1][x] == '1' || map[y + 1][x] == '\n' ||
		map[y + 1][x] == ' ' || map[y + 1][x] == '\t' || map[y + 1][x] == '\0')
		i++;
	if (i == 4)
		return (0);
	return (1);
}
