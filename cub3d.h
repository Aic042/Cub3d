/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/11/17 22:43:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1200
# define HEIGHT 700
# define PI 3.1415926535
# define TILE 64

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "lib/MLX42/include/MLX42/MLX42.h"
#include "lib/libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_player
{
	long x;
	long y;
	float angle;
	bool left_rotate;
	bool right_rotate;

} t_player;

typedef struct s_game
{
	mlx_t *mlx;
	mlx_image_t *image;
	char **map;
	void *win;
	char *pixel;
	int size_of_line;
	int	bpp;
	char *title;
	t_player player;
} t_game;


void	ft_my_hook(mlx_key_data_t keydata, void	*param);
bool touch (t_game *game, int player_x, int player_y);
void init_player(t_player *player);
void map_drawer(t_game *game);
char **get_map(void);
void init_game(t_game *game);
void pixel_placer(int x, int y, uint32_t color, t_game *game);
void draw_square(int x, int y, int size, uint32_t color, t_game *game);

#endif