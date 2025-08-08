/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/08/08 13:20:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 800
# define HEIGHT 600	
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "lib/MLX42/include/MLX42/MLX42.h"
#include "lib/libft/libft.h"
typedef struct s_game
{
	void *mlx;
	void *win;
	char *title;
} t_game;

#endif