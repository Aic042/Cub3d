/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:32:02 by root              #+#    #+#             */
/*   Updated: 2025/11/18 10:51:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game->mlx) {
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image) {
		mlx_terminate(game->mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	game->pixel = (char *)game->image->pixels;
	game->size_of_line = WIDTH * 4;
	game->bpp = 32;
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1) {
		mlx_terminate(game->mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->left_rotate = false;
	player->right_rotate = false;
}

//inicializar el player ^^