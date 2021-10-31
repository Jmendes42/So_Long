/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:55:13 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/16 13:08:22 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parser2(t_img *s_img)
{
	s_img->s_map.x = 0;
	s_img->pos_x = 0;
	margins(s_img, 1);
	s_img->s_map.x = 0;
	s_img->pos_x = 0;
	put_img(s_img, "images/grass5.XPM");
	map_error(s_img);
}

void	parser1(t_img *s_img)
{
	if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == '1'
			&& s_img->s_map.x == 0)
		put_img(s_img, "images/grassleft.xpm");
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == '1'
			&& s_img->s_map.x == s_img->s_map.max_x - 1)
		put_img(s_img, "images/grassright.xpm");
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == '1')
		put_img(s_img, "images/ground.xpm");
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == '0')
		put_img(s_img, "images/wall.xpm");
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == 'E')
		sub_parser1(s_img);
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == 'P')
		sub_parser2(s_img);
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == 'C')
		sub_parser3(s_img);
	else if (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == 'S')
		sub_parser4(s_img);
}

void	parser(t_img *s_img)
{
	s_img->s_map.y = 1;
	s_img->s_map.x = 1;
	put_img(s_img, "images/grass2.XPM");
	s_img->pos_x += 64;
	margins(s_img, 0);
	s_img->pos_y += 64;
	while (s_img->s_map.y < s_img->s_map.max_y - 1)
	{
		s_img->pos_x = 0;
		s_img->s_map.x = 0;
		while (s_img->s_map.x <= s_img->s_map.max_x)
		{
			parser1(s_img);
			s_img->pos_x += 64;
			s_img->s_map.x++;
		}
		s_img->s_map.y++;
		s_img->pos_y += 64;
	}
	parser2(s_img);
}
