/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:16:07 by root              #+#    #+#             */
/*   Updated: 2025/12/09 16:42:16 by sbolivar         ###   ########.fr       */
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
