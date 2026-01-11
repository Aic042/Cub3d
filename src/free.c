/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:40:30 by sbolivar          #+#    #+#             */
/*   Updated: 2026/01/11 15:50:10 by root             ###   ########.fr       */
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
	free(str);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->north.texture)
		mlx_delete_texture(game->north.texture);
	if (game->south.texture)
		mlx_delete_texture(game->south.texture);
	if (game->east.texture)
		mlx_delete_texture(game->east.texture);
	if (game->west.texture)
		mlx_delete_texture(game->west.texture);
	free_double(game->map);
	free_double(game->inf);
	free_double(game->paths);
	free(game->select_map);
	free(game->pixel);
	free(game->title);
	free(game);
}
