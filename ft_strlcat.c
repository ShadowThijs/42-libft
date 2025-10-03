/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:58:01 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/08/30 21:58:01 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;
	size_t	dlen;

	if (size == 0)
		return (ft_strlen(src));
	dlen = 0;
	while (dlen < size && dst[dlen])
		dlen++;
	ret = dlen + ft_strlen(src);
	if (size <= dlen)
		return (ret);
	i = 0;
	while (src[i] && (dlen + i) < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (ret);
}
