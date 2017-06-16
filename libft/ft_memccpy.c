/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:21:27 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/18 16:43:38 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned const char		*hold_src;
	unsigned char			*hold_dst;
	unsigned char			h;

	i = 0;
	hold_src = src;
	hold_dst = dst;
	h = c;
	while (i < n)
	{
		hold_dst[i] = hold_src[i];
		if (hold_dst[i] == h)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
