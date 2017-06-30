/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:16:42 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 01:18:12 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_p(char **tmp)
{
	char	*freeme;

	freeme = *tmp;
	*tmp = ft_strjoin("0x", *tmp);
	free(freeme);
}

void	dealhash(char **tmp, t_flag flags)
{
	char	*freeme;

	if (flags.hash == 0 || ft_strcmp("0", *tmp) == 0)
		return ;
	freeme = *tmp;
	if (flags.type == 'o')
		*tmp = ft_strjoin("0", *tmp);
	if (flags.type == 'x')
		*tmp = ft_strjoin("0x", *tmp);
	if (flags.type == 'X')
		*tmp = ft_strjoin("0X", *tmp);
	free(freeme);
}

int		ft_chartab(int fd, int tab, char c, t_flag flags)
{
	int	ret;

	ret = 0;
	if (tab > 0)
		tab = tab - 1;
	if (tab > 0)
		ret = tab;
	ret += 1;
	if (flags.tabside == 1)
		ft_putchar_fd(c, fd);
	while (tab-- > 0)
	{
		if (flags.zerotab)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		if (tab < 0)
			break ;
	}
	if (flags.tabside == 0)
		ft_putchar_fd(c, fd);
	return (ret);
}

void	handledot(char **str, t_flag flags)
{
	char	*freeme;
	int		hold;

	if (flags.dot == 0)
		return ;
	freeme = *str;
	if (ft_strlen(*str) < flags.pres)
	{
		hold = flags.pres - ft_strlen(*str);	
		while (hold--)
		{
			*str = ft_strjoin("0", *str);
//			free(freeme);
			freeme = *str;
		}
	}
}

int		ft_printtab(int fd, int tab, char *str, t_flag flags)
{
	int ret;
	int	track;

	ret = 0;
	handledot(&str, flags);
	track = flags.pres;
	if (tab > 0)
		tab = tab - ft_strlen(str);
	if (tab > 0)
		ret = tab;
	ret += ft_strlen(str);
	if (flags.tabside == 1)
	{
		if (flags.type == 's' && flags.dot == 1)
		{
			ft_putnstr_fd(str, flags.pres, fd);
			tab += ft_strlen(str) - flags.pres;
			ret = ret - ft_strlen(str) + flags.pres;
		}
		else
		{
			ft_putstr_fd(str, fd);
		}
	}
	while (flags.zerotab && (*str== '+' || *str == '0' || *str == 'x' || *str == 'X'))
		ft_putchar_fd(*str++, fd);
	while (tab-- > 0)
	{
		if (flags.zerotab && !flags.dot)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		if (tab < 0)
			break ;
	}
	if (flags.tabside == 0)
	{
		if (flags.type == 's' && flags.dot == 1 && *str != 0)
		{
			ft_putnstr_fd(str, flags.pres, fd);
			tab += ft_strlen(str) - flags.pres;
			ret = ret - ft_strlen(str) + flags.pres;
		}
		else
			ft_putstr_fd(str, fd);
	}
	return (ret);
}
