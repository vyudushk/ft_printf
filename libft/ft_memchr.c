/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:21:18 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/02 11:35:41 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		find;
	const unsigned char	*look;

	i = 0;
	find = c;
	look = (unsigned char*)s;
	while (i < n)
	{
		if (*(look + i) == find)
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
