/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:36:41 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/23 15:01:08 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	char		*res;
	const char	*hold;
	const char	*start;

	if ((!*big && !*little) || (*big && !*little))
		return ((char*)big);
	hold = little;
	start = big;
	while (*big && *little)
	{
		if (*big == *little)
		{
			res = (char*)big;
			while (*big++ == *little++)
				if (*little == 0)
					return (res);
			little = hold;
		}
		big = start++;
	}
	return (0);
}
