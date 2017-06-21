/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 22:47:43 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/18 16:37:58 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	cmp1 = (unsigned char*)s1;
	cmp2 = (unsigned char*)s2;
	while (*cmp1 && *cmp2 && *cmp1 == *cmp2)
	{
		cmp1++;
		cmp2++;
	}
	return (*cmp1 - *cmp2);
}
