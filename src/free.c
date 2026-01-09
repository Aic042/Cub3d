/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:40:30 by sbolivar          #+#    #+#             */
/*   Updated: 2026/01/09 12:39:34 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	free_game(t_game *game) // trabajar en esta funcion
{
	// if (game->image)
	// 	mlx_delete_image(game->mlx, game->image);
	// free(game->mlx);
	// free(game);
	// free(game->select_map);
	// free(game->pixel);
	// free(game->title);
	// free_double(game->map);
	// free_double(game->inf);
	// // free_double(game->paths);
	mlx_terminate(game->mlx);
	free(game);
}
