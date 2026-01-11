/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:18:14 by root              #+#    #+#             */
/*   Updated: 2026/01/11 15:37:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	distance(float x, float y) // para calcular la distancia ^^
{
	return (sqrt(x * x + y * y));
}

/* Update src/math_utils.c - Change touch to take float */
bool	touch(t_game *game, float px, float py)
{
	int	x;
	int	y;

	if (!game || !game->map)
		return (true);
	x = (int)(px / TILE);
	y = (int)(py / TILE);
	if (x < 0 || x >= game->size_x || y < 0 || y >= game->size_y)
		return (true);
	if (!game->map[y])
		return (true);
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

// Basicamente, no generas rashitos dentro de un tile