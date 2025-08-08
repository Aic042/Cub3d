/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:50:43 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/10 18:11:18 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (count(nb));
}
