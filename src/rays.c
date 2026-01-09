/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:19:52 by root              #+#    #+#             */
/*   Updated: 2026/01/09 13:19:19 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_ray_dir(t_ray *r, int ray_id, int num_rays, t_player *p)
{
	float	f_id;
	float	f_nr;
	float	camera_x;

	f_id = (float)ray_id;
	f_nr = (float)num_rays;
	camera_x = (2.0f * ray_id / (float)(num_rays - 1)) - 1.0f;
	r->dir_x = cos(p->angle) - sin(p->angle) * camera_x * (PI / 6.0f);
	r->dir_y = sin(p->angle) + cos(p->angle) * camera_x * (PI / 6.0f);
	r->map_x = (int)(p->x / TILE);
	r->map_y = (int)(p->y / TILE);
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
	init_dda_utils(r, p, pos_x, pos_y);
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
	int			y;
	int			tex_y;
	uint8_t		*p;
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
