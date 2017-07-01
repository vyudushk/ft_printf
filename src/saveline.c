/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 03:32:56 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 20:18:26 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	usave_line(uintmax_t *val, uintmax_t value, int *i)
{
	*val = value;
	*i = 0;
}

void	save_line(intmax_t *val, intmax_t *value, int *i)
{
	*val = *value;
	*i = 0;
	if (*value < 0)
		*value = *value * -1;
}

int		ifprefix(t_flag flags, char c)
{
	return (flags.zerotab &&
	(c == '+' || (c == '0' && !flags.dot) || c == 'x' || c == 'X'));
}

int		string_dot(t_flag *flags, char *str, int ret, int fd)
{
	if (flags->tabside == 1 && flags->type == 's' && flags->dot == 1)
	{
		ft_putnstr_fd(str, flags->pres, fd);
		flags->tab += ft_strlen(str) - flags->pres;
		ret = ret - ft_strlen(str) + flags->pres;
	}
	else if (flags->tabside == 0 && flags->type == 's'
			&& flags->dot == 1 && *str != 0)
	{
		ft_putnstr_fd(str, flags->pres, fd);
		flags->tab += ft_strlen(str) - flags->pres;
		ret = ret - ft_strlen(str) + flags->pres;
	}
	else
		ft_putstr_fd(str, fd);
	return (ret);
}
