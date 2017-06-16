/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:32:10 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:29:14 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*res;

	if (s == 0 || f == 0)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	res = (char*)malloc(sizeof(char) * len + 1);
	if (res == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
