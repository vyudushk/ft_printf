/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 20:54:48 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/30 21:02:21 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handle_print(char *tmp, int fd, t_flag flags, const char **input)
{
	int	ret;

	ret = 0;
	if (flags.type == 'o')
		dealhash(&tmp, flags);
	ret += ft_printtab(fd, tmp, flags);
	free(tmp);
	(*input)++;
	return (ret);
}
