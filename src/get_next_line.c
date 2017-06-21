/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyudushk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:31:07 by vyudushk          #+#    #+#             */
/*   Updated: 2017/06/16 11:27:32 by vyudushk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int				get_range(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] != c)
		i++;
	return (i);
}

static t_list	*get_fd_hold(int fd)
{
	static t_list	*hold;
	t_list			*lst;

	lst = hold;
	while (lst)
	{
		if ((int)lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("", 1);
	lst->content_size = fd;
	ft_lstadd(&hold, lst);
	return (lst);
}

static void		fill_hold(t_list *work, char *buff)
{
	char	*tmp;

	if (work->content == 0)
		work->content = (char*)buff;
	else
	{
		tmp = work->content;
		work->content = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	t_list		*lst;
	size_t		ret_read;
	size_t		i;
	char		*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	lst = get_fd_hold(fd);
	while (!ft_strchr(lst->content, '\n')
			&& (ret_read = read(fd, buff, BUFF_SIZE)))
		fill_hold(lst, ft_strndup(buff, ret_read));
	if (ret_read < BUFF_SIZE && ft_strlen(lst->content) == 0)
	{
		ft_strclr(*line);
		return (0);
	}
	tmp = lst->content;
	i = get_range(tmp, '\n');
	*line = (tmp[i] == '\n') ? (ft_strndup(tmp, i)) : (ft_strdup(lst->content));
	if ((ret_read == 0 && tmp[i] == 0))
		ft_strclr(lst->content);
	lst->content = (tmp[i] == '\n') ? (ft_strdup(tmp + i + 1)) : tmp;
	free(tmp);
	return (1);
}
