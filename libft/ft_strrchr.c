/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:36:51 by vyudushk          #+#    #+#             */
/*   Updated: 2017/03/29 15:32:34 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char		find;
	const char	*start;

	find = (char)c;
	start = s;
	while (*s != 0)
		s++;
	if (*s == find)
		return ((char*)s);
	while (s != start)
	{
		if (*s == find)
			return ((char *)s);
		s--;
	}
	if (*s == find)
		return ((char *)s);
	return (0);
}
