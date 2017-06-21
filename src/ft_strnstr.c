/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:51:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:32:02 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*hay;
	char	*nee;

	if ((!*big && !*little) || (*big && !*little))
		return ((char*)big);
	hay = (char*)big;
	nee = (char*)little;
	while (*hay && len > 0)
	{
		if (*hay == *nee)
		{
			if (ft_strlen(little) <= len)
			{
				if (ft_strncmp(hay, nee, ft_strlen(nee)) == 0)
					return (hay);
			}
			else
				return (NULL);
		}
		hay++;
		len--;
	}
	return (NULL);
}
