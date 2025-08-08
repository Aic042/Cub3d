/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:50:04 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/10 18:11:18 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		++i;
	while (nb)
	{
		++i;
		nb /= 10;
	}
	return (i);
}

int	ft_putunsigned(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putunsigned(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (count(nb));
}
