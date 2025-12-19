/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:46:52 by root              #+#    #+#             */
/*   Updated: 2025/12/19 09:38:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t rgba_from_rgb(int r, int g, int b)
{
	return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | 0xFF;
}

static const char *skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static int parse_number(const char **str, int *value)
{
	int num;

	num = 0;
	*str = skip_spaces(*str);
	if (!ft_isdigit(**str))
		return (0);
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	if (num > 255)
		return (0);
	*value = num;
	return (1);
}

static int parse_number(const char **s, int *value)
{
	int num;

	num = 0;
	*s = skip_spaces(*s);
	if (!ft_isdigit(**s))
		return (0);
	while (ft_isdigit(**s))
	{
		num = num * 10 + (**s - '0');
		(*s)++;
	}
	if (num > 255)
		return (0);
	*value = num;
	return (1);
}

int parse_fc_line(const char *line, uint32_t *out_color)
{
	const char *p;
	char        id;
	int         r, g, b;

	if (!line || !out_color)
		return (0);
	p = skip_spaces(line);
	id = *p++;
	if (id != 'F' && id != 'C')
		return (0);
	if (!parse_number(&p, &r))
		return (0);
	p = skip_spaces(p);
	if (*p++ != ',')
		return (0);
	if (!parse_number(&p, &g))
		return (0);
	p = skip_spaces(p);
	if (*p++ != ',')
		return (0);
	if (!parse_number(&p, &b))
		return (0);
	p = skip_spaces(p);
	if (*p != '\0' && *p != '\n')
		return (0);
	*out_color = rgba_from_rgb(r, g, b);
	return (1);
}

// if (line[0] == 'F')
// {
//     if (!parse_fc_line(line, &game->floor_color))
//         return (error("Invalid floor color line"));
// }
// else if (line[0] == 'C')
// {
//     if (!parse_fc_line(line, &game->ceiling_color))
//         return (error("Invalid ceiling color line"));
// }
// 
