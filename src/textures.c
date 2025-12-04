/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:23:07 by root              #+#    #+#             */
/*   Updated: 2025/12/04 08:05:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* New function in src/textures.c or main.c - Load textures (hardcoded for simplicity) */

#include "../cub3d.h"

void load_NO_SO_textures(t_game *game)
{
    // replace with new pngs in case we get them
    game->north.texture = mlx_load_png("./Sprites/Texture_Side1.png");
    if (!game->north.texture)
    {
        printf("Error loading north texture\n");
        exit(EXIT_FAILURE);
    }
    game->north.width = game->north.texture->width;
    game->north.height = game->north.texture->height;
    game->north.pixels = (uint32_t *)game->north.texture->pixels;
    //south
    game->south.texture = mlx_load_png("./Sprites/Texture_Side1.png");
    if (!game->south.texture)
    {
        printf("Error loading south texture\n");
        exit(EXIT_FAILURE);
    }
    game->south.width = game->south.texture->width;
    game->south.height = game->south.texture->height;
    game->south.pixels = (uint32_t *)game->south.texture->pixels;
}

void load_WE_EA_textures(t_game *game)
{
    // East
    game->east.texture = mlx_load_png("./Sprites/Texture_Side1.png");
    if (!game->east.texture)
    {
        printf("Error loading east texture\n");
        exit(EXIT_FAILURE);
    }
    game->east.width = game->east.texture->width;
    game->east.height = game->east.texture->height;
    game->east.pixels = (uint32_t *)game->east.texture->pixels;
    // West
    game->west.texture = mlx_load_png("./Sprites/Texture_Side1.png");
    if (!game->west.texture)
    {
        printf("Error loading west texture\n");
        exit(EXIT_FAILURE);
    }
    game->west.width = game->west.texture->width;
    game->west.height = game->west.texture->height;
    game->west.pixels = (uint32_t *)game->west.texture->pixels;
}
void	load_all_textures(t_game *game)
{
    load_NO_SO_textures(game);
    load_WE_EA_textures(game);
}