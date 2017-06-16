/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:56:14 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/21 15:50:21 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*hold_src;
	char		*hold_dst;

	i = 0;
	hold_src = src;
	hold_dst = dst;
	if (dst < src)
		while (i < len)
		{
			hold_dst[i] = hold_src[i];
			i++;
		}
	else if (dst > src)
		while (len)
		{
			hold_dst[len - 1] = hold_src[len - 1];
			len--;
		}
	return (dst);
}
