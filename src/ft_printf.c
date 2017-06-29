/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:39:37 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/29 00:51:19 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

size_t		handle_len(const char **in, t_length *len)
{
	const char	*input;
	size_t		count;

	input = *in;
	count = 0;
	while (*input == 'h' || *input == 'l' || *input == 'j' || *input == 'z')
	{
		len->h += (*input == 'h') ? 1 : 0;
		len->l += (*input == 'l') ? 1 : 0;
		len->j += (*input == 'j') ? 1 : 0;
		len->z += (*input == 'z') ? 1 : 0;
		input++;
		count++;
	}
	return (count);
}

int		start_print(int fd, const char *input, va_list args)
{
	t_flag		flags;
	t_length	len;
	int			tab;
	int			ret;
	char		*tmp;

	tab = 0;
	ret = 0;
	clear_len(&len);
	clear_flags(&flags);
	while (*input)
	{
		if (*input == '%')
		{
			flags.percent = 1;
			input++;
			if (*input == '-' && flags.zerotab == 0)
			{
				flags.tabside = BACK;
				input++;
			}
			else
				flags.tabside = FRONT;
			if (*input == '+')
			{
				flags.plus = 1;
				input++;
			}
			if (*input == ' ')
			{
				flags.space = 1;
				while (*input == ' ')
					input++;
			}
			if (*input == '#')
			{
				flags.hash = 1;
				input++;
			}
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
			input += handle_len(&input, &len);
			if (*input == 's' || *input == 'S')
			{
				tmp = va_arg(args, char*);
				if (tmp == NULL)
					ret += ft_printtab(fd, tab, "(null)", flags);
				else
					ret += ft_printtab(fd, tab, tmp, flags);
				input++;
				continue ;
			}
			if (*input == 'p')
			{
				tmp = ft_uitoa_base((size_t)va_arg(args, void*), 16, 0);
				handle_p(&tmp);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'd' || *input == 'i')
			{
				tmp = ft_itoa_base(set_cast(len, va_arg(args, intmax_t)), 10, 1, flags);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'D')
			{
				tmp = ft_itoa_base((long)va_arg(args, intmax_t), 10, 1, flags);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'o' && (flags.type = 'o'))
			{
				tmp = ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 8, 0);
				dealhash(&tmp, flags);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'u')
			{
				tmp = ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 10, 0);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'U')
			{
				tmp = ft_uitoa_base((long)va_arg(args, uintmax_t), 10, 0);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'x' && (flags.type = 'x'))
			{
				tmp = ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 16, 0);
				dealhash(&tmp, flags);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'X' && (flags.type = 'X'))
			{
				tmp = ft_uitoa_base(uset_cast(len, va_arg(args, uintmax_t)), 16, 1);
				dealhash(&tmp, flags);
				ret += ft_printtab(fd, tab, tmp, flags);
				free(tmp);
				input++;
				continue ;
			}
			if (*input == 'c' || *input == 'C')
			{
				ret += ft_chartab(fd, tab, (char)va_arg(args, int), flags);
				input++;
				continue ;
			}
			if (*input == '%' && flags.percent == 1)
			{
				ret += ft_chartab(fd, tab, '%', flags);
				input++;
				continue ;
			}
		}
		else if (*input)
		{
			tab = 0;
			flags.type = 0;
			clear_len(&len);
			clear_flags(&flags);
			ft_putchar_fd(*input, fd);
			flags.percent = 0;
			ret++;
		}
		if (*input == '\0')
			break ;
		input++;
	}
	return (ret);
}

int		ft_printf(const char *input, ...)
{
	va_list	args;

	va_start(args, input);
	return (start_print(1, input, args));
}
