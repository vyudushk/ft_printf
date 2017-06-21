/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:07:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/20 20:06:13 by vyudushk         ###   ########.fr       */
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
}				t_flag;

int		ft_printf(const char *input, ...);

#endif
