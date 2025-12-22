/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:18:10 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/22 12:55:27 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_placer(int x, int y, uint32_t color, t_game *game)
{
	int		i;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	i = y * game->size_of_line + x * 4;
	if (i + 3 >= WIDTH * HEIGHT * 4)
		return ;
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	game->pixel[i] = r;
	game->pixel[i + 1] = g;
	game->pixel[i + 2] = b;
	game->pixel[i + 3] = a;
}

void	draw_minimap(t_game *g, int my, int mx, int px)
{
	int		py;
	char	cell;
	float	mini_x;
	float	mini_y;

	while (my < g->size_y)
	{
		mx = 0;
		while (mx < g->size_x)
		{
			px = MM_OFFSET + mx * MM_TILE;
			py = MM_OFFSET + my * MM_TILE;
			cell = g->map[my][mx];
			if (cell == '1')
				draw_square_2(px, py, 0xFFFFFFFF, g);
			else if (cell == '0')
				draw_square_2(px, py, 0x000000FF, g);
			mx++;
		}
		my++;
	}
	mini_x = (g->player.x / TILE) * MM_TILE;
	mini_y = (g->player.y / TILE) * MM_TILE;
	draw_square_3(MM_OFFSET + mini_x - 2,
		MM_OFFSET + mini_y - 2, 0xFF0000FF, g);
}

void	draw_cleaner(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				pixel_placer(x, y, game->ceiling_color, game);
			else
				pixel_placer(x, y, game->floor_color, game);
			x++;
		}
		y++;
	}
}

void	init_dda_utils(t_ray *r, t_player *p, float pos_x, float pos_y)
{
	pos_x = p->x / TILE;
	pos_y = p->y / TILE;
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0f - pos_x) * r->delta_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_y = (pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0f - pos_y) * r->delta_y;
	}
}
