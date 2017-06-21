/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:11:39 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/09 15:29:08 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		fir;

	if (s1 == 0 || s2 == 0)
		return (0);
	res = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == 0)
		return (0);
	fir = 0;
	while (*s1)
	{
		res[fir] = *s1;
		s1++;
		fir++;
	}
	while (*s2)
	{
		res[fir] = *s2;
		s2++;
		fir++;
	}
	res[fir] = 0;
	return (res);
}
