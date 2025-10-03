/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:55:47 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/09/02 16:55:47 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	calc_mall(long nb)
{
	size_t	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = -nb;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	long	nb;

	nb = n;
	len = calc_mall(nb);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	ret[0] = '0';
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		return (ret);
	while (nb > 0)
	{
		ret[len-- - 1] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (ret);
}
