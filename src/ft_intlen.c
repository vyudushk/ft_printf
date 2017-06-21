/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:33:03 by vyudushk          #+#    #+#             */
/*   Updated: 2016/12/01 00:43:07 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is to count the number of digits. This function doesn't give special
** attention to negatives.
*/

int	ft_intlen(int n)
{
	int		res;

	if (n == 0)
		return (1);
	res = 0;
	if (n < 0)
		res++;
	while (n)
	{
		res++;
		n = n / 10;
	}
	return (res);
}
