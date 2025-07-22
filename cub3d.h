/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/07/22 11:40:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 800
# define HEIGHT 600	
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

struct cub3d
{
	void *mlx;
	void *win;
	char *title;
};

#endif