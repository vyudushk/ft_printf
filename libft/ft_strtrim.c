/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:22:25 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:01:00 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*res;

	if (s == 0)
		return (0);
	start = 0;
	while (ft_iswhite(s[start]) == 1)
		start++;
	end = 0;
	while (s[end] != 0)
		end++;
	end--;
	while (ft_iswhite(s[end]) == 1)
		end--;
	if (end < start)
	{
		res = (char*)malloc(sizeof(char));
		if (res == 0)
			return (0);
		*res = 0;
		return (res);
	}
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
