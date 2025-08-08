/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:47:31 by aingunza          #+#    #+#             */
/*   Updated: 2024/07/04 13:22:14 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_str(const char *s1, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	if (start > end)
		return (ft_strdup(""));
	str = ft_calloc(end - start + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	return (str);
}

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]) && j >= i)
		j--;
	return (new_str(s1, i, j));
}
