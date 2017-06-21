/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:07:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/21 04:04:06 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

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

int		ft_printf(const char *input, ...);
char	*ft_itoa_base(int value, int base, int set);
char	*ft_uitoa_base(size_t value, int base, int set);

#endif
