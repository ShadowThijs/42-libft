/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:58:01 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/08/30 21:58:01 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_do_something(const char *big, const char *little,
	size_t len, size_t *i)
{
	size_t	j;

	j = 0;
	while (big[*i] == little[j] && little[j] != '\0' && *i < len)
	{
		*i += 1;
		j += 1;
	}
	return (j);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	if ((!big && len == 0) || (!little && len == 0))
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			temp = i;
			j = ft_do_something(big, little, len, &i);
			if (little[j] == '\0')
				return ((char *)big + temp);
			i = temp;
		}
		i++;
	}
	return (NULL);
}
