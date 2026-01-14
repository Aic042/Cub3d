/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2026/01/14 15:35:52 by sbolivar         ###   ########.fr       */
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
	mlx_texture_t	*texture;
	uint32_t		*pixels;//  RGBA format
	int				width;
	int				height;
}	t_texture;

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
	float		dir_x;
	float		dir_y;
	float		delta_x;
	float		delta_y;
	float		side_x;
	float		side_y;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	float		perp_dist;
	float		wall_x;
	int			draw_start;
	int			draw_end;
	int			wall_height;
	int			tex_x;
	float		tex_pos;
	float		tex_step;
}	t_ray;

typedef struct s_game
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;

	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*select_map;
	char		**map;
	char		**paths;
	char		**inf;
	int			x1;
	int			x2;
	int			size_color;
	int			size_x;
	int			size_y;
	void		*win;
	float		move_x;
	float		move_y;
	char		*pixel;
	int			size_of_line;
	int			bpp;
	char		*title;
	t_player	player;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
}	t_game;

//			Rays! 🍊
void		calc_ray_dir(t_ray *r, int ray_id, int num_rays, t_player *p);
void		init_dda(t_ray *r, t_player *p);
t_texture	*select_wall_texture(t_game *g, t_ray *r);
void		calc_wall_params(t_ray *r, t_player *p, t_game *g, t_texture **tex);
void		draw_ray_column(t_game *g, t_ray *r, t_texture *tex, int x);

void		get_text(int fd, char **str, t_game *game, int i);
char		*give_map_line(char *map, char *temp);
void		free_game(t_game *game);
void		ft_my_hook(mlx_key_data_t keydata, void	*param);
bool		touch(t_game *game, float px, float py);
int			player_case(int x, int y, char **map);
int			zero_case(int x, int y, char **map);
int			parse_fc_line(const char *line, uint32_t *out_color);
void		get_paths(t_game *game);
void		special_strlcpy(char *dst, char *src, size_t size, size_t j);
int			wall_case(int x, int y, char **map);
int			space_case(int x, int y, char **map);
void		init_player(t_player *player);
void		init_vars(t_game *game, t_player *player);
void		map_drawer(t_game *game);
int			ft_strlen_strings(char **av);
char		**get_map(t_game *game, int y, int player);
int			map_parse(t_game *game, int i, int y);
int			check_cases(int	*x, int y, char **map, t_player *player);
int			check_walls(char **map, t_player *player);
void		init_game(t_game *game);
void		pixel_placer(int x, int y, uint32_t color, t_game *game);
void		draw_minimap(t_game *g, int py, int px, int mx);
void		draw_cleaner(t_game *game);
void		init_player(t_player *player);
void		pixel_placer(int x, int y, uint32_t color, t_game *game);
void		map_drawer(t_game *game);
void		init_game(t_game *game);
void		draw_square_1(int x, int y, uint32_t color, t_game *game);
float		distance(float x, float y);
void		draw_square_2(int x, int y, uint32_t color, t_game *game);
void		draw_square_3(int x, int y, uint32_t color, t_game *game);
void		load_all_textures(t_game *game);
void		init_dda_utils(t_ray *r, t_player *p, float pos_x, float pos_y);
int			ft_validate_file(char	*map_path);
int			comp_map(t_game *game);
int			comp_map(t_game *game);
void		free_double(char **str);
int			comp_paths(t_game *game);

#endif