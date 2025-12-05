/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:15 by root              #+#    #+#             */
/*   Updated: 2025/12/05 12:45:49 by aingunza         ###   ########.fr       */
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

void draw_cleaner(t_game *game)
{
    int y = 0;
    int x;

    game->ceiling_color = 0x708090FF;  // Cielo azul claro (perfecto)
    game->floor_color   = 0x4E342EFF;  // Marrón tierra bonito
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

void	draw_fov(t_game *g, t_player *p)
{
	t_ray	r;
	t_texture *tex;
	int		ray;
	int		num_rays;

	num_rays = WIDTH / 1;
//dividir por un numero superior a 1 puede dividir la pantalla de derecha a iquierda!
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

void setup_player_spawn(t_game *game)
{
    float pos_x;
    float pos_y;
    float angle;

    if (!game->map)
    {
        printf("Error: mapa inválido o sin jugador\n");
        mlx_terminate(game->mlx);
        free(game);
        exit(EXIT_FAILURE);
    }

    pos_x = (float)game->player.potition_x + 0.5f;
    pos_y = (float)game->player.potition_y + 0.5f;

    game->player.x = pos_x * (float)TILE;
    game->player.y = pos_y * (float)TILE;

    if (game->player.facing == 'N')
        angle = 3.0f * PI / 2.0f;
    else if (game->player.facing == 'S')
        angle = PI / 2.0f;
    else if (game->player.facing == 'E')
        angle = 0.0f;
    else if (game->player.facing == 'W')
        angle = PI;
    else
        angle = 0.0f;

    game->player.angle = angle;
}

int	main(int argc, char **argv)
{
	t_game		*game;
	t_player	*player;

	(void)argc;
	(void)argv;
	// if(argc > 2)
	// 	return(printf("error con argc\n"), -1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->map = get_map(game);
	player = &game->player;
	(void)player;
	// if(!ft_validate_file(argv[2]))
	// 	return(-1);
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
