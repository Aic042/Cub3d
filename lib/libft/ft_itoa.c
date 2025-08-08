/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:25:30 by aingunza          #+#    #+#             */
/*   Updated: 2024/07/05 09:26:51 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pre_conv(int len, int n)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	if (n < 0)
		tmp[0] = '-';
	tmp[len] = '\0';
	return (tmp);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len, n);
	if (!result)
		return (NULL);
	i = len - 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		result[i--] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	if (n == 0)
		result[0] = '0';
	return (result);
}
