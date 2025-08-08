/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:42:18 by aingunza          #+#    #+#             */
/*   Updated: 2024/07/02 13:44:21 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	l;

	if (n == 0 || dst == src)
		return (dst);
	l = 0;
	while (l < n)
	{
		((char *)dst)[l] = ((char *)src)[l];
		l++;
	}
	return (dst);
}
