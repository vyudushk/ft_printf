/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:29:36 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/02 17:46:33 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*new;
	size_t	i;
	size_t	n;

	new = (char*)malloc(sizeof(char) * ft_strlen(str));
	if (new == 0)
		return (NULL);
	i = 0;
	while (str[i] != 0)
		i++;
	i--;
	n = 0;
	while (i != 0)
	{
		new[n] = str[i];
		n++;
		i--;
	}
	new[n] = str[i];
	n++;
	new[n] = 0;
	return (new);
}
