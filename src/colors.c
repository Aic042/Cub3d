/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:32:44 by sbolivar          #+#    #+#             */
/*   Updated: 2025/12/22 13:28:58 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	rgba_from_rgb(int r, int g, int b)
{
	return (((uint32_t)r << 24) | ((uint32_t)g << 16)
		| ((uint32_t)b << 8) | 0xFF);
}

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static int	parse_number(const char **s, int *value)
{
	int	num;

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

int	parse_color_values(const char **p, int *r, int *g, int *b)
{
	if (!parse_number(p, r))
		return (0);
	*p = skip_spaces(*p);
	if (**p != ',')
		return (0);
	(*p)++;
	if (!parse_number(p, g))
		return (0);
	*p = skip_spaces(*p);
	if (**p != ',')
		return (0);
	(*p)++;
	if (!parse_number(p, b))
		return (0);
	*p = skip_spaces(*p);
	return (1);
}

int	parse_fc_line(const char *line, uint32_t *out_color)
{
	const char	*p;
	char		id;
	int			r;
	int			g;
	int			b;

	if (!line || !out_color)
		return (0);
	p = skip_spaces(line);
	id = *p++;
	if (id != 'F' && id != 'C')
		return (0);
	if (!parse_color_values(&p, &r, &g, &b))
		return (0);
	p = skip_spaces(p);
	if (*p != '\0' && *p != '\n')
		return (0);
	*out_color = rgba_from_rgb(r, g, b);
	return (1);
}
