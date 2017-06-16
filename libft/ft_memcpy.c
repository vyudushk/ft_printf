/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:50:58 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/01 15:15:42 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*hold_src;
	char		*hold_dst;

	i = 0;
	hold_src = src;
	hold_dst = dst;
	while (i < n)
	{
		hold_dst[i] = hold_src[i];
		i++;
	}
	return (dst);
}
