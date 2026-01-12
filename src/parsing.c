/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:16:07 by root              #+#    #+#             */
/*   Updated: 2026/01/12 13:01:38 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_validate_file(char	*map_path)
{
	char	*file;

	file = ft_strrchr(map_path, '.');
	if (file == NULL || ft_strcmp(file, ".cub") != 0)
	{
		ft_printf("Error with the file\n");
		return (0);
	}
	return (1);
}

void	special_strlcpy(char *dst, char *src, size_t size, size_t j)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		if (src[j] == '\n')
			dst[i] = '\0';
		else
			dst[i] = src[j];
		i++;
		j++;
	}
	if (size != 0)
		dst[i] = '\0';
}

void	get_paths(t_game *game)
{
	int	i;

	i = 0;
	game->paths = ft_calloc(sizeof(char *), 5);
	if (!game->paths)
		return ;
	while (i < 4)
	{
		game->paths[i] = ft_calloc(sizeof(char), (ft_strlen(game->inf[i]) - 2));
		special_strlcpy(game->paths[i], game->inf[i],
			(ft_strlen(game->inf[i]) - 2), 3);
		i++;
	}
}

void	get_text(int fd, char **str, t_game *game, int I)
{
	char	*temp;
	int		j;
	int		i;

	i = 0;
	j = 6;
	temp = get_next_line(fd);
	if (I != 0)
		j = game->size_y;
	while (temp != NULL && j > 0)
	{
		str[i] = ft_calloc(sizeof(char *), game->size_x + 1);
		str[i] = give_map_line(str[i], temp);
		free(temp);
		j--;
		if (j != 0)
		{
			i++;
			temp = get_next_line(fd);
		}
	}
	if (game->inf[4])
		parse_fc_line(game->inf[4], &game->floor_color);
	if (game->inf[5])
		parse_fc_line(game->inf[5], &game->ceiling_color);
}
