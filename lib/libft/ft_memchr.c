/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:01:52 by aingunza          #+#    #+#             */
/*   Updated: 2024/07/02 13:25:33 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	uc;

	str = (unsigned char *) s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
