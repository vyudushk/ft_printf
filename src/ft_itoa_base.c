/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:06:58 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/21 17:38:51 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*setup(int i, intmax_t *val, int base)
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

void	save_line(intmax_t *val, intmax_t *value, int *i)
{
	*val = *value;
	*i = 0;
	if (*value < 0)
		*value = *value * -1;
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

char	*ft_itoa_base(intmax_t value, int base, int set)
{
	char		*bases;
	int			almost[64];
	int			i;
	intmax_t	val;
	char		*res;

	if (value == -2147483648 || value == 0)
		return ((value == 0) ? "0" : "-2147483648");
	bases = set_bases(set);
	save_line(&val, &value, &i);
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
	free(bases);
	return (res);
}

void	usave_line(uintmax_t *val, uintmax_t value, int *i)
{
	*val = value;
	*i = 0;
}

char	*ft_uitoa_base(uintmax_t value, int base, int set)
{
	char		*bases;
	int			almost[64];
	int			i;
	uintmax_t	val;
	char		*res;

	if (value == 0)
		return (0);
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
