/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:52:14 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/01 00:35:33 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		is_neg;

	if (0 == (res = (char*)malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (0);
	i = ft_intlen(n);
	is_neg = (n < 0) ? (-1) : (1);
	res[i] = 0;
	i--;
	if (n == 0)
		res[i] = '0';
	while (n)
	{
		if (n > 0)
			res[i] = (n % 10) + 48;
		else
			res[i] = -1 * (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_neg == -1)
		res[i] = '-';
	return (res);
}
