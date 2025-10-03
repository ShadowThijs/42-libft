/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:55:40 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/09/01 23:55:40 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	if (!s)
		return (0);
	if (!c)
		return (1);
	i = 0;
	words = 1;
	if (s[0] == c)
		words = 0;
	while (s[i])
	{
		if (i > 0 && s[i - 1] && s[i - 1] == c && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static char	*copy_word(const char *s, char c)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	k;

	ret = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	if (!s)
	{
		ret[0] = 0;
		return (ret);
	}
	i = 0;
	k = 0;
	while (s[i])
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			ret[k++] = copy_word(s + i, c);
		i++;
	}
	ret[k] = 0;
	return (ret);
}
