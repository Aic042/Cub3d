#include "../cub3d.h"

void	ft_my_hook(mlx_key_data_t keydata, void *param)
{
    t_game  *game = (t_game *)param;
    t_player *player = &game->player;
    int speed = 5;
    (void)keydata;
    float angle_speed = 0.033; //33sssssssssssss
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_A))
        player->angle -= angle_speed;
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx, MLX_KEY_D))
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx, MLX_KEY_W)) {
        player->x += cos(player->angle) * speed;
        player->y += sin(player->angle) * speed;
    }
    if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx, MLX_KEY_S)) {
        player->x -= cos(player->angle) * speed;
        player->y -= sin(player->angle) * speed;
    }
}

// ft_stop_music();

// if (mlx_is_key_down(mlx, MLX_KEY_R) || (mlx_is_key_down(mlx, MLX_KEY_KP_0)))
// 	transform(game);