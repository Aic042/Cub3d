/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:43:37 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/17 16:43:52 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	map_0(t_player *player, char **map, int *x, int y)
{
	player->facing = map[y][*x];
	map[y][*x] = '0';
	player->potition_x = *x;
	player->potition_y = y;
	return (map[y][*x]);
}

int	check_cases(int *x, int y, char **map, t_player *player)
{
	int	check;

	while (map[y][*x])
	{
		if (map[y][*x] == 'N' || map[y][*x] == 'S' || map[y][*x] == 'E'
			|| map[y][*x] == 'W')
		{
			check = player_case(*x, y, map);
			if (!check)
				map[y][*x] = map_0(player, map, x, y);
			else
				return (1);
		}
		else if (map[y][*x] == '0')
			check = zero_case(*x, y, map);
		else if (map[y][*x] == '1')
			check = wall_case(*x, y, map);
		else if (map[y][*x] == ' ' || map[y][*x] == '\t')
			check = space_case(*x, y, map);
		if (!check)
			(*x)++;
		else
			return (1);
	}
	return (0);
}

int	check_walls(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 1;
	while (map[y + 1])
	{
		x = 0;
		while (map[y][x] == ' ' || map[y][x] == '\t')
			x++;
		if (map[y][x] == '1')
		{
			x++;
			if (!check_cases(&x, y, map, player))
				y++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	parse_inf(t_game *game)
{
	char	**inf;

	inf = game->inf;
	if (inf[0][0] != 'N' || inf[0][1] != 'O' || game->inf[0][2] != ' ')
		return (1);
	if (inf[1][0] != 'S' || inf[1][1] != 'O' || game->inf[1][2] != ' ')
		return (1);
	if (inf[2][0] != 'W' || inf[2][1] != 'E' || game->inf[2][2] != ' ')
		return (1);
	if (inf[3][0] != 'E' || inf[3][1] != 'A' || game->inf[3][2] != ' ')
		return (1);
	if (inf[4][0] != 'F' || game->inf[4][1] != ' ')
		return (1);
	if (inf[5][0] != 'C' || game->inf[5][1] != ' ')
		return (1);
	return (0);
}

int	map_parse(t_game *game, int i, int y)
{
	char	**map;

	map = game->map;
	while (1)
	{
		if (map[y][i] == '1' || map[y][i] == ' ' || map[y][i] == '\t')
			i++;
		else if (map[y][i] == '\n' || map[y][i] == '\0')
		{
			i = 0;
			if (y == (ft_strlen_strings(map) - 1))
				break ;
			if (!check_walls(map, &game->player))
				y = (ft_strlen_strings(map) - 1);
			else
				return (1);
		}
		else
			return (1);
	}
	if (parse_inf(game))
		return (1);
	return (0);
}
