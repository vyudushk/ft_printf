/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:39:37 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/21 04:16:16 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		start_print(int fd, const char *input, va_list args)
{
	t_flag	flags;
	int		tab;

	tab = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == '%')
			{
				ft_putchar_fd('%', fd);
				continue ;
			}
			if (*input == '-' && flags.zerotab == 0)
			{
				flags.tabside = BACK;
				input++;
			}
			else
				flags.tabside = FRONT;
			if (*input == '0')
			{
				flags.zerotab = 1;
				flags.tabside = FRONT;
				input++;
			}
			while (*input >= '0' && *input <= '9')
			{
				tab = tab * 10;
				tab = tab + (*input - '0');
				input++;
			}
			if (*input == 's')
			{
				ft_putstr_fd(va_arg(args, char*), fd);
				input++;
				continue ;
			}
			if (*input == 'p')
			{
				ft_putstr_fd(ft_uitoa_base((size_t)va_arg(args, void*), 16, 0),fd);
				input++;
				continue ;
			}
			if (*input == 'd' || *input == 'i')
			{
				ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10, 1), fd);
				input++;
				continue ;
			}
			if (*input == 'o')
			{
				ft_putstr_fd(ft_uitoa_base(va_arg(args, size_t), 8, 0), fd);
				input++;
				continue ;
			}
			if (*input == 'u')
			{
				ft_putstr_fd(ft_uitoa_base(va_arg(args, size_t), 10, 0), fd);
				input++;
				continue ;
			}
			if (*input == 'x')
			{
				ft_putstr_fd(ft_uitoa_base(va_arg(args, size_t), 16, 1), fd);
				input++;
				continue ;
			}
			if (*input == 'X')
			{
				ft_putstr_fd(ft_uitoa_base(va_arg(args, size_t), 16, 0), fd);
				input++;
				continue ;
			}
			if (*input == 'c')
			{
				ft_putchar_fd((char)va_arg(args, int),fd);
				input++;
				continue ;
			}
		}
		else if (*input)
		{
			ft_putchar_fd(*input, fd);
		}
		if (*input == '\0')
			break ;
		input++;
	}
	return (0);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;

	va_start(args, input);
	return start_print(0, input, args);
}
