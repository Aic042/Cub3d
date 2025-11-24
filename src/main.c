/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:15 by root              #+#    #+#             */
/*   Updated: 2025/11/24 11:25:48 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_placer(int x, int y, uint32_t color, t_game *game)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	int i = y * game->size_of_line + x * 4; // 4 bytes per pixel (RGBA)
	if (i + 3 < WIDTH * HEIGHT * 4)
	{
		game->pixel[i] = (color >> 24) & 0xFF;     // Red
		game->pixel[i + 1] = (color >> 16) & 0xFF; // Green
		game->pixel[i + 2] = (color >> 8) & 0xFF;  // Blue
		game->pixel[i + 3] = color & 0xFF;         // Alpha
	}
}

// int collision(int wall_x, int wall_y, t_game *game)
// {
//     int x = wall_x / TILE;
//     int y = wall_y / TILE;
// }

void	draw_cleaner(t_game *game)
{
	int y, x;
	uint32_t background_color = 0x000044FF;
		// Example: dark gray with full alpha
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_placer(x, y, background_color, game);
			x++;
		}
		y++;
	}
}

void	draw_fov(t_game *game, t_player *player)
{
	float	start_angle;
	float	end_angle;
	float	step;
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	float spread = PI / 6; // 30° field of view
	int num_rays = 64;     // How many rays to draw
	start_angle = player->angle - (spread / 2);
	end_angle = player->angle + (spread / 2);
	step = spread / num_rays;
	ray_angle = start_angle;
	// Iteramos over all the rays usando un while
	while (ray_angle <= end_angle)
	{
		ray_x = player->x;
		ray_y = player->y;
		cos_angle = cos(ray_angle);
		sin_angle = sin(ray_angle);
		// Draweamos each ray until it hits a wall!
		while (!touch(game, ray_x, ray_y))
		{
			pixel_placer(ray_x, ray_y, 0x00FF00FF, game);
			ray_x += cos_angle;
			ray_y += sin_angle;
		}
		ray_angle += step;
	}
}

void	render(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	// Clear the screen
	draw_cleaner(game);
	// Draw the map
	map_drawer(game);
	// Draw the player
	draw_square(game->player.x, game->player.y, 10, 0x00FF00FF, game);
	draw_fov(game, &game->player);
}

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->map = get_map(game);
	if (!game->map)
		return (free(game), EXIT_FAILURE);
	init_game(game);
	init_player(&game->player);
	map_drawer(game);
	mlx_key_hook(game->mlx, &ft_my_hook, game);
	mlx_loop_hook(game->mlx, &render, game); // draw every frame
	mlx_loop(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
