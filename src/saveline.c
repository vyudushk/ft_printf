/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 03:32:56 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 03:33:09 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	usave_line(uintmax_t *val, uintmax_t value, int *i)
{
	*val = value;
	*i = 0;
}

void	save_line(intmax_t *val, intmax_t *value, int *i)
{
	*val = *value;
	*i = 0;
	if (*value < 0)
		*value = *value * -1;
}
