/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:36:34 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/02 21:30:06 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != 0)
	{
		while (*s == c && *s != 0)
			s++;
		if (*s != c && *s != 0)
			count++;
		while (*s != c && *s != 0)
			s++;
	}
	return (count);
}

static int	word_len(char const *s, char c, int word)
{
	int		count;
	int		len;

	count = 0;
	len = 0;
	while (*s != 0)
	{
		while (*s == c && *s != 0)
			s++;
		if (*s != c && *s != 0)
			count++;
		if (count == word)
		{
			len = 0;
			while (*s != c && *s != 0)
			{
				s++;
				len++;
			}
			return (len);
		}
		while (*s != c && *s != 0)
			s++;
	}
	return (len);
}

static char	**allo_mem(char **res, char const *s, char c)
{
	int	i;

	i = 0;
	while (i < count_words(s, c))
	{
		res[i] = (char*)malloc(sizeof(char) * word_len(s, c, i) + 1);
		if (res[i] == 0)
		{
			i = 0;
			while (i < count_words(s, c))
			{
				res[i] = 0;
				i++;
			}
			res = 0;
			return (0);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		n;
	int		j;

	if ((s == 0 || c == 0) || (0 == (res =
					(char**)malloc(sizeof(char*) * count_words(s, c) + 1))))
		return (0);
	res = allo_mem(res, s, c);
	if (res == 0)
		return (0);
	i = 0;
	n = 0;
	while (i < count_words(s, c))
	{
		j = 0;
		while (s[n] == c && s[n] != 0)
			n++;
		while (s[n] != c && s[n] != 0)
			res[i][j++] = s[n++];
		res[i++][j] = 0;
	}
	return (res);
}
