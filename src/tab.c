/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:16:42 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/22 20:48:31 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printtab(int	fd, int tab, char *str, int mode)
{
	int ret;

	if (tab > 0)
		tab = tab - ft_strlen(str);
	ret = tab;
	ret += ft_strlen(str);
	if (mode == 1)
		ft_putstr_fd(str, fd);
	while (tab--)
	{
		ft_putchar(' ');
		if (tab < 0)
			break ;
	}
	if (mode == 0)
		ft_putstr_fd(str, fd);
	return (ret);
}
