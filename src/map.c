/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:17 by root              #+#    #+#             */
/*   Updated: 2025/11/26 15:41:56 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(int x, int y, int size, uint32_t color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pixel_placer(x + i, y, color, game);
		pixel_placer(x + i, y + size - 1, color, game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		pixel_placer(x, y + i, color, game);
		pixel_placer(x + size - 1, y + i, color, game);
		i++;
	}
}

void	map_drawer(t_game *game)
{
	int	color;
	int	y;
	int	x;
	char **map; // debe recibirlo del parseo =D
	
	map = game->map;
	y = 0;
	color = 0x00FFFF;
		// blue color! Note: Aprender a como ver eso del 0xFFFFFFFF (º~º)
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * 32, y * 32, 64, color, game);
			x++;
		}
		y++;
	}
}
