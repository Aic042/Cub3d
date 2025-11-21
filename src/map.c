/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:17 by root              #+#    #+#             */
/*   Updated: 2025/11/21 13:51:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_square(int x, int y, int size, uint32_t color, t_game *game)
{
	int i = 0;
	while (i < size) {
		pixel_placer(x + i, y, color, game); // Top side
		pixel_placer(x + i, y + size - 1, color, game); // Bottom side
		i++;
	}
	i = 0;
	while (i < size) {
		pixel_placer(x, y + i, color, game); // Left side
		pixel_placer(x + size - 1, y + i, color, game); // Right side
		i++;
	}
}

char **get_map(void) //temporal, se eliminara tras el parseo
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000100001";
    map[3] = "100000100000001";
    map[4] = "100000000000001";
    map[5] = "100000010000001";
    map[6] = "100001000000001";
    map[7] = "100000100000001";
    map[8] = "100010000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

void map_drawer(t_game *game)
{
    char **map = game->map; //debe recibirlo del parseo =D
    int color;
    int y = 0;
    
    color = 0x0000FFFF; //blue color! Note: Aprender a como ver eso del 0xFFFFFFFF (º~º)
    
    while(map[y])
    {
        int x = 0;
        while (map[y][x])
        {
            if(map[y][x] == '1')
            draw_square(x *64, y* 64, 64, color, game);
            x++;
        }
        y++;
        
    } 
}
