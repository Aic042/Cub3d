/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:13 by root              #+#    #+#             */
/*   Updated: 2025/08/06 14:14:35 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 800
# define HEIGHT 600	
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "MLX42/include/MLX42/MLX42.h"

struct cub3d
{
	void *mlx;
	void *win;
	char *title;
};

#endif