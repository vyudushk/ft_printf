/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:10:20 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:28:47 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*hold_dst;
	const char	*hold_src;
	size_t		hold_size;
	size_t		res;

	hold_size = size;
	hold_dst = dst;
	hold_src = src;
	while (*hold_dst && hold_size--)
		hold_dst++;
	res = (hold_dst - dst);
	hold_size = (size - res);
	if (hold_size == 0)
		return (res + ft_strlen(src));
	while (*hold_src != 0)
	{
		if (hold_size != 1)
		{
			*hold_dst++ = *hold_src;
			hold_size--;
		}
		hold_src++;
	}
	*hold_dst = 0;
	return (res + (hold_src - src));
}
