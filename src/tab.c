/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:16:42 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 16:25:18 by vyudushk         ###   ########.fr       */
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

/*
** handledot has a major memory leak
*/

void	handledot(char **str, t_flag flags)
{
	char	*freeme;
	int		hold;
	int		space;

	if (flags.dot == 0)
		return ;
	space = 0;
	freeme = *str;
	while (*freeme == ' ')
	{
		freeme++;
		space++;
	}
	*str = freeme;
	if ((int)ft_strlen(*str) < flags.pres)
	{
		hold = flags.pres - ft_strlen(*str);
		while (hold--)
		{
			*str = ft_strjoin("0", *str);
			freeme = *str;
		}
		if (space)
			*str = ft_strjoin(" ", *str);
	}
}

int		ft_printtab(int fd, char *str, t_flag flags)
{
	int ret;
	int	track;

	ret = 0;
	handledot(&str, flags);
	track = flags.pres;
	if (flags.tab > 0)
		flags.tab = flags.tab - ft_strlen(str);
	if (flags.tab > 0)
		ret = flags.tab;
	ret += ft_strlen(str);
	if (flags.tabside == 1)
	{
		if (flags.type == 's' && flags.dot == 1)
		{
			ft_putnstr_fd(str, flags.pres, fd);
			flags.tab += ft_strlen(str) - flags.pres;
			ret = ret - ft_strlen(str) + flags.pres;
		}
		else
			ft_putstr_fd(str, fd);
	}
	while (flags.zerotab && (*str == '+' || (*str == '0' &&
					!flags.dot) || *str == 'x' || *str == 'X'))
		ft_putchar_fd(*str++, fd);
	while (flags.tab-- > 0)
	{
		if (flags.zerotab && !flags.dot)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		if (flags.tab < 0)
			break ;
	}
	if (flags.tabside == 0)
	{
		if (flags.type == 's' && flags.dot == 1 && *str != 0)
		{
			ft_putnstr_fd(str, flags.pres, fd);
			flags.tab += ft_strlen(str) - flags.pres;
			ret = ret - ft_strlen(str) + flags.pres;
		}
		else
			ft_putstr_fd(str, fd);
	}
	return (ret);
}
