/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:17 by root              #+#    #+#             */
/*   Updated: 2025/11/26 00:00:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(int x, int y, int size, uint32_t color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pixel_placer(x + i, y, color, game);            // Top side
		pixel_placer(x + i, y + size - 1, color, game); // Bottom side
		i++;
	}
	i = 0;
	while (i < size)
	{
		pixel_placer(x, y + i, color, game);            // Left side
		pixel_placer(x + size - 1, y + i, color, game); // Right side
		i++;
	}
}

void	map_drawer(t_game *game)
{
	int	color;
	int	y;
	int	x;

	char **map = game->map; // debe recibirlo del parseo =D
	y = 0;
	color = 0x00FFFF;
		// blue color! Note: Aprender a como ver eso del 0xFFFFFFFF (º~º)
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * 64, y * 64, 64, color, game);
			x++;
		}
		y++;
	}
}
