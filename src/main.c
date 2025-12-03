/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:15 by root              #+#    #+#             */
/*   Updated: 2025/12/03 13:40:55 by root             ###   ########.fr       */
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
		return;
	i = y * game->size_of_line + x * 4;
	if (i + 3 >= WIDTH * HEIGHT * 4)
		return;
	r = (color >> 24) & 0xFF;
	g = (color >> 16) & 0xFF;
	b = (color >> 8) & 0xFF;
	a = color & 0xFF;
	game->pixel[i] = r;
	game->pixel[i + 1] = g;
	game->pixel[i + 2] = b;
	game->pixel[i + 3] = a;
}


void draw_minimap(t_game *g)
{
	for (int my = 0; my < g->size_y; my++)
	{
		for (int mx = 0; mx < g->size_x; mx++)
		{
			int px = MM_OFFSET + mx * MM_TILE;
			int py = MM_OFFSET + my * MM_TILE;
			char cell = g->map[my][mx];
			if (cell == '1')
				draw_square(px, py, MM_TILE, 0xFFFFFFFF, g);     // pared
			else if (cell == 'D')
				draw_square(px, py, MM_TILE, 0x8080FFFF, g);     // puerta
			else
				draw_square(px, py, MM_TILE, 0x000000FF, g);     // suelo
		}
	}
	int ppx = MM_OFFSET + (int)(g->player.x * MM_TILE);
	int ppy = MM_OFFSET + (int)(g->player.y * MM_TILE);
	draw_square(ppx - 2, ppy - 2, 4, 0xFF0000FF, g);
}

void	draw_cleaner(t_game *game)
{
	int y = 0;
	int x;

	game->ceiling_color = 0x87CEEBFF;  // Sky blue con alpha
	game->floor_color   = 0x4444444F;  // Gris oscuro con alpha
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

void	calc_ray_dir(t_ray *r, int ray_id, int num_rays, t_player *p)
{
	float	f_id;
	float	f_nr;
	float	camera_x;

	f_id = (float)ray_id;
	f_nr = (float)num_rays;

	camera_x = 2.0f * f_id / f_nr - 1.0f;

	r->dir_x = cos(p->angle) - sin(p->angle) * camera_x * (PI / 6.0f);
	r->dir_y = sin(p->angle) + cos(p->angle) * camera_x * (PI / 6.0f);

	r->map_x = (int)(p->x / TILE);
	r->map_y = (int)(p->y / TILE);
}


void	perform_dda(t_ray *r, t_game *g)
{
	while (1)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (touch(g, r->map_x * TILE, r->map_y * TILE))
			break;
	}
}


void	init_dda(t_ray *r, t_player *p)
{
	float	pos_x;
	float	pos_y;
	float	inv_x;
	float	inv_y;

	pos_x = p->x / TILE;
	pos_y = p->y / TILE;

	if (r->dir_x == 0)
		r->delta_x = 1e30;
	else
	{
		inv_x = 1 / r->dir_x;
		r->delta_x = fabs(inv_x);
	}

	if (r->dir_y == 0)
		r->delta_y = 1e30;
	else
	{
		inv_y = 1 / r->dir_y;
		r->delta_y = fabs(inv_y);
	}

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

t_texture	*select_wall_texture(t_game *g, t_ray *r)
{
	if (r->side == 1)
	{
		if (r->step_y > 0)
			return (&g->north);
		else
			return (&g->south);
	}
	else
	{
		if (r->step_x > 0)
			return (&g->west);
		else
			return (&g->east);
	}
}

void	calc_wall_params(t_ray *r, t_player *p, t_game *g, t_texture **tex)
{
	float	pos_x;
	float	pos_y;
	float	wall_hit;

	pos_x = p->x / TILE;
	pos_y = p->y / TILE;
	if (r->side == 0)
		r->perp_dist = r->side_x - r->delta_x;
	else
		r->perp_dist = r->side_y - r->delta_y;
	r->wall_height = (int)(HEIGHT / r->perp_dist);
	r->draw_start = HEIGHT / 2 - r->wall_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = HEIGHT / 2 + r->wall_height / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	*tex = select_wall_texture(g, r);
	if (r->side == 0)
		wall_hit = pos_y + r->perp_dist * r->dir_y;
	else
		wall_hit = pos_x + r->perp_dist * r->dir_x;

	r->wall_x = wall_hit - floor(wall_hit);
	r->tex_x = (int)(r->wall_x * (*tex)->width);
}

void	draw_ray_column(t_game *g, t_ray *r, t_texture *tex, int x)
{
	int		y;
	int		tex_y;
	uint8_t	*p;
	uint32_t	color;

	r->tex_step = (float)tex->height / (float)r->wall_height;
	r->tex_pos = r->draw_start;
	r->tex_pos -= HEIGHT / 2;
	r->tex_pos += r->wall_height / 2;
	r->tex_pos *= r->tex_step;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex_y = (int)r->tex_pos;
		r->tex_pos += r->tex_step;

		p = &tex->texture->pixels[(tex_y * tex->width + r->tex_x) * 4];

		color = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];

		pixel_placer(x, y, color, g);
		y++;
	}
}

void	draw_fov(t_game *g, t_player *p)
{
	t_ray	r;
	t_texture *tex;
	int		ray;
	int		num_rays;

	num_rays = WIDTH / 1;

	ray = 0;
	while (ray < num_rays)
	{
		calc_ray_dir(&r, ray, num_rays, p);
		init_dda(&r, p);
		perform_dda(&r, g);
		calc_wall_params(&r, p, g, &tex);
		draw_ray_column(g, &r, tex, ray);
		ray++;
	}
}

//probando el mini mapa
void	render(void *param)
{
	t_game *game;
	game = (t_game *)param;
	// Clear the screen
	draw_cleaner(game);
	// Draw the map
	// // Draw the player
	draw_fov(game, &game->player);
	// map_drawer(game);
	draw_minimap(game);
}

void	setup_player_spawn(t_game *game)
{
	float	pos_x;
	float	pos_y;
	float	angle;

	if (!game->map)
	{
		printf("Error: Invalid map or no player found\n");
		mlx_terminate(game->mlx);
		free(game);
		exit(EXIT_FAILURE);
	}

	pos_x = (float)game->player.potition_y + 0.5f;
	pos_y = (float)game->player.potition_x + 0.5f;

	game->player.x = pos_x * (float)TILE;
	game->player.y = pos_y * (float)TILE;

	if (game->player.facing == 'N')
		angle = (3.0f * PI) / 2.0f;
	else if (game->player.facing == 'S')
		angle = PI / 2.0f;
	else if (game->player.facing == 'E')
		angle = 0.0f;
	else
		angle = PI;

	game->player.angle = angle;
}

int	main(void)
{
	t_game		*game;
	t_player	*player;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->map = get_map(game);
	player = &game->player;
	(void)player;
	init_game(game);
	init_player(&game->player);
	load_all_textures(game);
	setup_player_spawn(game);
	mlx_key_hook(game->mlx, &ft_my_hook, game);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_loop(game->mlx);

	free(game);
	return (EXIT_SUCCESS);
}

