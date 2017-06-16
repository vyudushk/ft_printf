/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:29:26 by vyudushk          #+#    #+#             */
/*   Updated: 2016/11/28 21:01:54 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (res == 0)
		return (NULL);
	res->content = (void*)malloc(content_size);
	if (res->content == 0)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
	}
	else
	{
		res->content = ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
		res->next = NULL;
	}
	return (res);
}
