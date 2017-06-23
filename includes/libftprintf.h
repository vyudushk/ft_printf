/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:07:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/22 22:10:02 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define FRONT 0
# define BACK 1

typedef struct s_flag
{
	int	tabside;
	int	zerotab;
	int	plus;
	int	hash;
	int	space;
}				t_flag;

typedef struct	s_length
{
	int	hh;
	int	h;
	int	l;
	int	ll;
	int	j;
	int	z;
}				t_length;

int			ft_printf(const char *input, ...);
char		*ft_itoa_base(intmax_t value, int base, int set);
char		*ft_uitoa_base(size_t value, int base, int set);

intmax_t	set_cast(t_length len, intmax_t castme);
uintmax_t	uset_cast(t_length len, uintmax_t castme);

int			ft_printtab(int fd, int tab, char *str, t_flag flags);

#endif
