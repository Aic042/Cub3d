/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:40:30 by sbolivar          #+#    #+#             */
/*   Updated: 2026/01/13 12:44:55 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_paths(char **str)
{
	int	i;

	i = 0;
	if (!str)
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
	free_paths(game->paths);
	free(game->select_map);
	free(game->title);
	free(game);
}
