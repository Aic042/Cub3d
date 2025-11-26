/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:15 by root              #+#    #+#             */
/*   Updated: 2025/11/26 14:36:17 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_placer(int x, int y, uint32_t color, t_game *game)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return;
	int i = y * game->size_of_line + x * 4; // red, green, bule y alpha (RGBA)
	if (i + 3 < WIDTH * HEIGHT * 4) 
	{
		game->pixel[i] = (color >> 24) & 0xFF; // R
		game->pixel[i + 1] = (color >> 16) & 0xFF; // G
		game->pixel[i + 2] = (color >> 8) & 0xFF; // B
		game->pixel[i + 3] = color & 0xFF; // Alpha como en blender ^^
	}
}

void	draw_cleaner(t_game *game)
{
	int y, x;
	uint32_t background_color = 0x0000FFF; // Example: dark gray with full alpha
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

//para mas grados en el field of view 30, 45, 60, 75, 90 respectivamente
void draw_fov(t_game *game, t_player *player)
{
    float spread = PI / 6;      // 30° field of view
    int num_rays = 2048;         // Number of rays
    float start_angle = player->angle - (spread / 2);
    float step = spread / num_rays;
    float ray_angle = start_angle;
    int ray_id = 0;

    while (ray_id < num_rays)
    {
        float ray_x = player->x;
        float ray_y = player->y;
        float cos_angle = cos(ray_angle);
        float sin_angle = sin(ray_angle);
		//esto si lo quieres en 2D
		// while (!touch(game, ray_x, ray_y))
        // {
        //     pixel_placer(ray_x, ray_y, 0x00FF00FF, game); // debug ray
        //     ray_x += cos_angle;
        //     ray_y += sin_angle;
        // }
        while (!touch(game, ray_x, ray_y))
        {
            ray_x += cos_angle;
            ray_y += sin_angle;
        }
        float dist = distance(ray_x - player->x, ray_y - player->y);
        dist *= cos(ray_angle - player->angle);
        float wall_height = (TILE / dist) * 400;
        int start_y = (HEIGHT - wall_height) / 2;
        int end_y = start_y + wall_height;
        int column_x = (float)ray_id / num_rays * WIDTH;
        while (start_y < end_y)
			pixel_placer(column_x, start_y++, 0xFFFFFFFF, game);

        ray_angle += step;
        ray_id++;
    }
}
//probando el mini mapa

void	render(void *param)
{
	t_game *game = (t_game *)param;
	// Clear the screen
	draw_cleaner(game);
	// Draw the map
	// // Draw the player
	// draw_square(game->player.x, game->player.y, 10, 0x00FF00FF, game);
	draw_fov(game, &game->player);
	// map_drawer(game);
}

int	main(void)
{
	t_game *game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->map = get_map(game);
	init_game(game);
	init_player(&game->player);
	// map_drawer(game);
	mlx_key_hook(game->mlx, &ft_my_hook, game);
	mlx_loop_hook(game->mlx, &render, game); // draw every frame

	mlx_loop(game->mlx);

	free(game);
	return (EXIT_SUCCESS);
}
