/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:17:21 by root              #+#    #+#             */
/*   Updated: 2025/07/22 15:51:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int line_size(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
	printf("Window created with size %d x %d\n", WIDTH, HEIGHT);
	printf("press ESC to exit\n");
	if (!mlx)
	{
		fprintf(stderr, "Failed to initialize mlx\n");
		return 1;
	}
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Cub3D Test");
    mlx_loop(mlx);
	mlx_mouse_show(mlx, win);
	if(mlx_key_hook(mlx, KEY_ESC, NULL))
	{
		mlx_destroy_window(mlx, win);
	}
    return 0;
}

// derecha e izquierda giras pero no te mueves
// arriba y abajo te mueves pero no giras