/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:03:08 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:09:17 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*res;
	char	*hold;
	size_t	i;

	res = (void*)malloc(size);
	if (res == 0)
		return (0);
	else
	{
		hold = res;
		i = 0;
		while (i < size)
		{
			hold[i] = 0;
			i++;
		}
		return (res);
	}
}
