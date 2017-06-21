/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 02:13:45 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/16 02:16:46 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	res = (char*)malloc(len + 1);
	if (res == NULL)
		return (0);
	res[len] = 0;
	return ((char*)ft_memcpy(res, s1, len));
}
