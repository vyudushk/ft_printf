/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:16:42 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/19 17:16:52 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(int tab, char *str, int mode)
{
	tab = tab - ft_strlen(str);
	if (mode == 1)
		ft_putstr(str);
	while (tab--)
	{
		ft_putchar(' ');
		if (tab < 0)
			break ;
	}
	if (mode == 0)
		ft_putstr(str);
	ft_putchar(' ');
}
