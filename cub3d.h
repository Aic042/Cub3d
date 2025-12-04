/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/12/04 08:24:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1200
# define HEIGHT 700
# define PI 3.141592653509
# define TILE 64
# define BABY_TILE 8
# define MM_TILE 15
# define MM_OFFSET 20

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

/* In cub3d.h - Already good, but ensure t_texture has correct fields */
typedef struct s_texture
{
    mlx_texture_t *texture;
    uint32_t *pixels;  // RGBA format
    int width;
    int height;
} t_texture;

typedef struct s_player
{
	float	x;
	float	y;
	int		potition_x;
	int		potition_y;
	float	angle;
	bool	left_rotate;
	char	facing;
	bool	right_rotate;
}	t_player;

typedef struct s_ray
{
	float dir_x;
	float dir_y;
	float delta_x;
	float delta_y;
	float side_x;
	float side_y;
	int   step_x;
	int   step_y;
	int   map_x;
	int   map_y;
	int   side;
	float perp_dist;
	float wall_x;
	int   draw_start;
	int   draw_end;
	int   wall_height;
	int   tex_x;
	float tex_pos;
	float tex_step;
}	t_ray;


typedef struct s_game
{
	
	t_texture   north;
    t_texture   south;
    t_texture   east;
    t_texture   west;

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
	uint32_t	ceiling_color;
	uint32_t	floor_color;
}	t_game;


//			Rays! 🍊
void	calc_ray_dir(t_ray *r, int ray_id, int num_rays, t_player *p);
void	init_dda(t_ray *r, t_player *p);
t_texture	*select_wall_texture(t_game *g, t_ray *r);
void	calc_wall_params(t_ray *r, t_player *p, t_game *g, t_texture **tex);
void	draw_ray_column(t_game *g, t_ray *r, t_texture *tex, int x);

//
void	ft_my_hook(mlx_key_data_t keydata, void	*param);
bool touch(t_game *game, float px, float py);
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
int		check_cases(int	*x, int y, char **map, t_player *player);
int		check_walls(char **map, t_player *player);
void	init_game(t_game *game);
void	pixel_placer(int x, int y, uint32_t color, t_game *game);
void	draw_square(int x, int y, int size, uint32_t color, t_game *game);
// bool	touch(t_game *game, int player_x, int player_y);
void	init_player(t_player *player);
void	map_drawer(t_game *game);
void	init_game(t_game *game);
void	draw_square(int x, int y, int size, uint32_t color, t_game *game);
float	distance(float x, float y);
void	load_all_textures(t_game *game);
#endif