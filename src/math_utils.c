/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:18:14 by root              #+#    #+#             */
/*   Updated: 2025/11/26 15:58:01 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	distance(float x, float y) // para calcular la distancia ^^
{
	return (sqrt(x * x + y * y));
}

bool	touch(t_game *game, int player_x, int player_y) // Calcular el touch =w=
{
	int x;
	int y;
	
	x = player_x / TILE;
	y = player_y / TILE;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}
// Basicamente, no generas rashitos dentro de un tile