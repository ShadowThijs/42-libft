/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:58:01 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/08/30 21:58:01 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ret;
	size_t			i;
	size_t			total;

	total = n * size;
	if (n != 0 && total / n != size)
		return (NULL);
	ret = malloc(total);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < (n * size))
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}
