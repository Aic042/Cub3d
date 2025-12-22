/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:17 by root              #+#    #+#             */
/*   Updated: 2025/12/18 17:07:43 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square_1(int x, int y, uint32_t color, t_game *game)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		pixel_placer(x + i, y, color, game);
		pixel_placer(x + i, y + 64 - 1, color, game);
		i++;
	}
	i = 0;
	while (i < 64)
	{
		pixel_placer(x, y + i, color, game);
		pixel_placer(x + 64 - 1, y + i, color, game);
		i++;
	}
}

void	draw_square_2(int x, int y, uint32_t color, t_game *game)
{
	int	i;

	i = 0;
	while (i < MM_TILE)
	{
		pixel_placer(x + i, y, color, game);
		pixel_placer(x + i, y + MM_TILE - 1, color, game);
		i++;
	}
	i = 0;
	while (i < MM_TILE)
	{
		pixel_placer(x, y + i, color, game);
		pixel_placer(x + MM_TILE - 1, y + i, color, game);
		i++;
	}
}

void	draw_square_3(int x, int y, uint32_t color, t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		pixel_placer(x + i, y, color, game);
		pixel_placer(x + i, y + 4 - 1, color, game);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pixel_placer(x, y + i, color, game);
		pixel_placer(x + 4 - 1, y + i, color, game);
		i++;
	}
}

void	map_drawer(t_game *game)
{
	int		color;
	int		y;
	int		x;
	char	**map;

	map = game->map;
	y = 0;
	color = 0x00FFFF;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square_1(x * 32, y * 32, color, game);
			x++;
		}
		y++;
	}
}
