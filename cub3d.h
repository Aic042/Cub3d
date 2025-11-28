/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/11/28 15:10:39 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1200
# define HEIGHT 700
# define PI 3.141592653509
# define TILE 64
# define BABY_TILE 8

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	int			size_x;
	int			size_y;
	void		*win;
	char		*pixel;
	int			size_of_line;
	int			bpp;
	char		*title;
	t_player	player;
}	t_game;

void	ft_my_hook(mlx_key_data_t keydata, void	*param);
bool	touch(t_game *game, int player_x, int player_y);
int		player_case(int x, int y, char **map);
int		zero_case(int x, int y, char **map);
int		wall_case(int x, int y, char **map);
int		space_case(int x, int y, char **map);
void	init_player(t_player *player);
void	init_vars(t_game *game, t_player *player);
void	map_drawer(t_game *game);
int		ft_strlen_strings(char **av);
char	**get_map(t_game *game);
int		map_parse(t_game *game);
int		check_cases(int	*x, int y, char **map);
int		check_walls(char **map);
void	init_game(t_game *game);
void	pixel_placer(int x, int y, uint32_t color, t_game *game);
void	draw_square(int x, int y, int size, uint32_t color, t_game *game);
bool	touch(t_game *game, int player_x, int player_y);
void	init_player(t_player *player);
void	map_drawer(t_game *game);
void	init_game(t_game *game);
void	pixel_placer(int x, int y, uint32_t color, t_game *game);
void	draw_square(int x, int y, int size, uint32_t color, t_game *game);
float	distance(float x, float y);
#endif