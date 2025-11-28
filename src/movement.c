/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:59:39 by aingunza          #+#    #+#             */
/*   Updated: 2025/11/28 16:23:46 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vertical_keys(t_game *game, t_player *player, int speed)
{
	float new_x, new_y;

	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		new_x = player->x - (-sin(player->angle)) * speed * 0.5;
		new_y = player->y - (cos(player->angle)) * speed * 0.5;
		if (!touch(game, new_x, new_y))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		new_x = player->x - (sin(player->angle)) * speed * 0.5;
		new_y = player->y - (-cos(player->angle)) * speed * 0.5;
		if (!touch(game, new_x, new_y))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
}

void	horizontal_keys(t_game *game, t_player *player, int speed)
{
	float new_x, new_y;

	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		new_x = player->x + cos(player->angle) * speed;
		new_y = player->y + sin(player->angle) * speed;
		if (!touch(game, new_x, new_y))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		new_x = player->x - cos(player->angle) * speed;
		new_y = player->y - sin(player->angle) * speed;
		if (!touch(game, new_x, new_y))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
}

void	ft_my_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_player	*player;
	int			speed;
	float		angle_speed;

	game = (t_game *)param;
	player = &game->player;
	speed = 5;
	angle_speed = 0.033;
	(void)keydata;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		player->angle -= angle_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	horizontal_keys(game, player, speed);
	vertical_keys(game, player, speed);
}

// int	check_collisions(t_game *game, t_player *player)
// {
// 	if(player->x == )
// }
// ft_stop_music();

// if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
// 	transform(game);