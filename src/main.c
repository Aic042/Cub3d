/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:13:15 by root              #+#    #+#             */
/*   Updated: 2026/01/13 14:26:50 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		if (touch(g, (float)r->map_x * TILE + TILE * 0.5f,
				(float)r->map_y * TILE + TILE * 0.5f))
			break ;
	}
}

void	draw_fov(t_game *g, t_player *p)
{
	t_ray		r;
	t_texture	*tex;
	int			ray;
	int			num_rays;

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

void	render(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	draw_cleaner(game);
	draw_fov(game, &game->player);
	draw_minimap(game, 0, 0, 0);
}

void	setup_player_spawn(t_game *game, float angle, float pos_x, float pos_y)
{
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
	game->move_x = game->player.x;
	game->move_y = game->player.y;
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

	if (argc != 2)
		return (printf("error con argc\n"), -1);
	if (!ft_validate_file(argv[1]))
		return (printf("error con argc\n"), -1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	ft_bzero(game, sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	game->select_map = argv[1];
	game->map = get_map(game, 0, 0);
	if (!game->map)
		return (free_game(game), EXIT_FAILURE);
	init_game(game);
	init_player(&game->player);
	load_all_textures(game);
	setup_player_spawn(game, 0, 0, 0);
	mlx_key_hook(game->mlx, &ft_my_hook, game);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_loop(game->mlx);
	return (free_game(game), EXIT_SUCCESS);
}
