/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:06:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 03:32:52 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*setup(int i, intmax_t *val, int base, t_flag flags)
{
	char	*res;

	if (*val < 0 || flags.plus || flags.space)
		i++;
	if ((res = (char*)malloc(i * sizeof(char))) == 0)
		return (NULL);
	if (*val < 0 && base == 10)
	{
		res[0] = '-';
		*val = 1;
	}
	else if (flags.plus)
	{
		res[0] = '+';
		*val = 1;
	}
	else if (flags.space)
	{
		res[0] = ' ';
		*val = 1;
	}
	else
		*val = 0;
	return (res);
}

char	*set_bases(int set)
{
	char	*res;

	if (set)
		res = ft_strdup("0123456789ABCDEF");
	else
		res = ft_strdup("0123456789abcdef");
	return (res);
}

char	*ft_itoa_base(intmax_t value, int base, int set, t_flag flags)
{
	char		*bases;
	int			almost[64];
	int			i;
	intmax_t	val;
	char		*res;

	if (value == -2147483648 || value == 0)
		return ((value == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	bases = set_bases(set);
	save_line(&val, &value, &i);
	while (value != 0)
	{
		almost[i++] = value % base;
		value = value / base;
	}
	i--;
	if ((res = setup(i, &val, base, flags)) == 0)
		return (NULL);
	while (i >= 0)
		res[val++] = bases[almost[i--]];
	res[val] = 0;
	free(bases);
	return (res);
}

char	*ft_uitoa_base(uintmax_t value, int base, int set)
{
	char		*bases;
	int			almost[64];
	int			i;
	uintmax_t	val;
	char		*res;

	if (value == 0)
		return (ft_strdup("0"));
	bases = set_bases(set);
	usave_line(&val, value, &i);
	while (value != 0)
	{
		almost[i++] = value % base;
		value = value / base;
	}
	i--;
	if ((res = malloc(i * sizeof(char))) == 0)
		return (NULL);
	val = 0;
	while (i >= 0)
		res[val++] = bases[almost[i--]];
	res[val] = 0;
	free(bases);
	return (res);
}
