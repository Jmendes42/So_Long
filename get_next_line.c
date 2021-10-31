/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:48:19 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/17 18:23:53 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	elsa(int index, int fd, char **saved, char **line)
{
	*line = ft_substr(saved[fd], 0, index);
	free(saved[fd]);
	saved[fd] = 0;
	return (0);
}

static int	values(int ret, int fd, char **saved, char **line)
{
	int		index;
	char	*temp;

	index = 0;
	if (!saved[fd] && !ret)
	{
		*line = ft_strdup("");
		return (0);
	}
	while (saved[fd][index] != '\n' && saved[fd][index] != '\0')
		index++;
	if (saved[fd][index] == '\n')
	{
		*line = ft_substr(saved[fd], 0, index);
		temp = ft_substr(saved[fd], index + 1, ft_strlen(saved[fd]));
		free(saved[fd]);
		saved[fd] = temp;
		return (1);
	}
	else
		return (elsa(index, fd, saved, line));
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	static char	*saved[100000];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	if (read(fd, 0, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE) > 0;
	while (ret)
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup("");
		temp = ft_strjoin(saved[fd], buf);
		free(saved[fd]);
		saved[fd] = temp;
		if (ft_strchr(saved[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (values(ret, fd, saved, line));
}
