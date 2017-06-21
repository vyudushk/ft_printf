/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:06:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/19 16:43:47 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*setup(int i, int *val, int base)
{
	char	*res;

	if ((res = (char*)malloc(i * sizeof(char))) == 0)
		return (NULL);
	if (*val < 0 && base == 10)
	{
		res[0] = '-';
		*val = 1;
	}
	else
		*val = 0;
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	char	*bases;
	int		almost[64];
	int		i;
	int		val;
	char	*res;

	if (value == -2147483648 || value == 0)
		return ((value == 0) ? "0" : "-2147483648");
	bases = ft_strdup("0123456789ABCDEF");
	i = 0;
	val = value;
	if (value < 0)
		value = value * -1;
	while (value != 0)
	{
		almost[i++] = value % base;
		value = value / base;
	}
	i--;
	if ((res = setup(i, &val, base)) == 0)
		return (NULL);
	while (i >= 0)
		res[val++] = bases[almost[i--]];
	res[val] = 0;
	return (res);
}