/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:16:42 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/22 22:11:08 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printtab(int	fd, int tab, char *str, t_flag flags)
{
	int ret;

	if (tab > 0)
		tab = tab - ft_strlen(str);
	ret = tab;
	ret += ft_strlen(str);
	if (flags.tabside == 1)
		ft_putstr_fd(str, fd);
	while (tab--)
	{
		if (flags.zerotab)
			ft_putchar('0');
		else
			ft_putchar(' ');
		if (tab < 0)
			break ;
	}
	if (flags.tabside == 0)
		ft_putstr_fd(str, fd);
	return (ret);
}
