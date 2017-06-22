/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:39:37 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/21 17:26:04 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		start_print(int fd, const char *input, va_list args)
{
	t_flag		flags;
	t_length	len;
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
			if (*input == 'h')
			{
				if (*(input + 1) == 'h')
				{
					len.hh = 1;
					input++;
				}
				else
					len.h = 1;
				input++;
			}
			if (*input == 'l')
			{
				if (*(input + 1) == 'l')
				{
					len.ll = 1;
					input++;
				}
				else
					len.l = 1;
				input++;
			}
			if (*input == 'j')
			{
				len.j = 1;
				input++;
			}
			if (*input == 'z')
			{
				len.z = 1;
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
				ft_putstr_fd(ft_itoa_base(set_cast(len, va_arg(args, intmax_t)), 10, 1), fd);
				input++;
				continue ;
			}
			if (*input == 'o')
			{
				ft_putstr_fd(ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 8, 0), fd);
				input++;
				continue ;
			}
			if (*input == 'u')
			{
				ft_putstr_fd(ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 10, 0), fd);
				input++;
				continue ;
			}
			if (*input == 'x')
			{
				ft_putstr_fd(ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 16, 1), fd);
				input++;
				continue ;
			}
			if (*input == 'X')
			{
				ft_putstr_fd(ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 16, 0), fd);
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
