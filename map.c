/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:12:52 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/21 11:01:51 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(t_img *s_img)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*list;

	ret = 1;
	list = NULL;
	line = NULL;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		error(s_img, "MAP READING");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_lstadd_back(&list, ft_lstnew((void *)ft_strdup(line)));
		free(line);
	}
	init_map(s_img, list);
	close(fd);
	return (0);
}

void	map_error3(t_img *s_img)
{
	if (s_img->s_map.error_p != 1)
		error(s_img, "WRONG NUMBER OF PLAYERS");
	if (s_img->max_c == 0)
		error(s_img, "NO COLLECTIBLES");
	if (s_img->s_map.error_e != 1)
		error(s_img, "WRONG NUMBER OF EXITS");
}

void	map_error2(t_img *s_img)
{
	while (s_img->s_map.y < s_img->s_map.max_y)
	{
		s_img->s_map.x = 0;
		while (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x])
		{
			if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != '1'
				&& s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != 'C'
				&& s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != 'P'
				&& s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != 'S'
				&& s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != 'E'
				&& s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] != '0')
				error(s_img, "ERROR: FORBIDEN MAP CHARACTER");
			if (s_img->s_map.map[s_img->s_map.y][0] != '1')
				error(s_img, "MAP OPEN");
			if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.max_x - 1] != '1')
				error(s_img, "MAP OPEN");
			s_img->s_map.x++;
		}
		if (s_img->s_map.x != s_img->s_map.max_x)
			error(s_img, "MAP OPEN");
		s_img->s_map.y++;
	}
	map_error3(s_img);
}

void	map_error(t_img *s_img)
{
	s_img->s_map.y = 1;
	s_img->s_map.x = 0;
	while (s_img->s_map.map[0][s_img->s_map.x])
	{
		if (s_img->s_map.map[0][s_img->s_map.x] != '1')
			error(s_img, "MAP OPEN");
		s_img->s_map.x++;
	}
	s_img->s_map.x = 0;
	while (s_img->s_map.map[s_img->s_map.max_y - 1][s_img->s_map.x])
	{
		if (s_img->s_map.map[s_img->s_map.max_y - 1][s_img->s_map.x] != '1')
			error(s_img, "MAP OPEN");
		s_img->s_map.x++;
	}
	if (s_img->s_map.x != s_img->s_map.max_x)
		error(s_img, "MAP OPEN");
	s_img->s_map.x = 0;
	map_error2(s_img);
}
