/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 16:33:18 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/21 17:24:35 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	set_cast(t_length len, intmax_t castme)
{
	if (len.hh)
		return ((char)castme);
	else if (len.h)
		return ((short)castme);
	else if (len.l)
		return ((long)castme);
	else if (len.ll)
		return ((long long)castme);
	else if (len.j)
		return ((intmax_t)castme);
	else if (len.z)
		return ((size_t)castme);
	else
		return ((int)castme);
}

uintmax_t	uset_cast(t_length len, uintmax_t castme)
{
	if (len.hh)
		return ((unsigned char)castme);
	else if (len.h)
		return ((unsigned short)castme);
	else if (len.l)
		return ((unsigned long)castme);
	else if (len.ll)
		return ((unsigned long long)castme);
	else if (len.j)
		return ((uintmax_t)castme);
	else if (len.z)
		return ((size_t)castme);
	else
		return ((unsigned int)castme);
}