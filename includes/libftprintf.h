/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:07:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 03:48:10 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define FRONT 0
# define BACK 1

typedef struct	s_flag
{
	int		tabside;
	int		zerotab;
	int		plus;
	int		hash;
	int		space;
	int		percent;
	char	type;
	int		dot;
	size_t	pres;
	int		tab;
}				t_flag;

typedef struct	s_length
{
	int	h;
	int	l;
	int	j;
	int	z;
}				t_length;

int				ft_printf(const char *input, ...);
char			*ft_itoa_base(intmax_t value, int base, int set, t_flag flags);
char			*ft_uitoa_base(uintmax_t value, int base, int set);

intmax_t		set_cast(t_length len, intmax_t castme);
uintmax_t		uset_cast(t_length len, uintmax_t castme);

int				ft_printtab(int fd, char *str, t_flag flags);
int				ft_chartab(int fd, int tab, char c, t_flag flags);

void			clear_flags(t_flag *flags);
void			dealhash(char **tmp, t_flag flags);

void			clear_len(t_length *len);
void			handle_p(char **tmp);

void			usave_line(uintmax_t *val, uintmax_t value, int *i);
void			save_line(intmax_t *val, intmax_t *value, int *i);

#endif
