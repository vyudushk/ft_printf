/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:39:37 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/20 16:56:43 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		start_print(int fd, const char *input, va_list args)
{
	t_flag	flags;
	int		tab;

	tab = 0;
	while (*input++)
	{
		if (*input == '%')
		{
			input++;
			if (*input == '%')
			{
				ft_putchar_fd('%', fd);
				continue ;
			}
			if (*input == '\0')
				break ;
			if (*input == '0')
			{
				flags.zerotab = 1;
				flags.tabside = FRONT;
				input++;
			}
			if (*input == '-' && flags.zerotab == 0)
			{
				flags.tabside = BACK;
				input++;
			}
			else
				flags.tabside = FRONT;
			while (*input >= '0' && *input <= '9')
			{
				tab = tab * 10;
				tab = tab + (*input - '0');
				input++;
			}
			if (*input == 's')
			{
				ft_putstr_fd((char*)va_arg(args, char*), fd);
			}
		}
	}
	return (0);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;

	va_start(args, input);
	return start_print(0, input, args);
}
