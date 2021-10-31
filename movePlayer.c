/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:38:45 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/18 13:00:44 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_r(t_img *s_img, int keycode)
{
	s_img->s_player.path = "images/chompyR.xpm";
	if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] == '0'
			|| s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] == 'C'
			|| (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1]
			== 'E'
			&& s_img->c == s_img->max_c)
			|| s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1]
			== 'S')
	{
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] == 'C')
			s_img->c++;
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] == 'E')
			destroy(s_img);
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] == 'S')
			destroy(s_img);
		else
			s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1] = 'P';
		move_r1(s_img);
	}
}

void	move_l(t_img *s_img, int keycode)
{
	s_img->s_player.path = "images/chompyL.xpm";
	if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] == '0'
			|| s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] == 'C'
			|| (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1]
				== 'E'
			&& s_img->c == s_img->max_c)
			|| s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1]
			== 'S')
	{
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] == 'C')
			s_img->c++;
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] == 'E')
			destroy(s_img);
		if (s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] == 'S')
			destroy(s_img);
		else
			s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1] = 'P';
		move_l1(s_img);
	}
}

void	move_u(t_img *s_img, int keycode, int control)
{
	if (s_img->s_map.map[s_img->s_player.y - 1][s_img->s_player.x] == '0')
	{
		s_img->s_map.map[s_img->s_player.y - 1][s_img->s_player.x] = 'P';
		s_img->s_map.map[s_img->s_player.y][s_img->s_player.x] = '0';
		s_img->pos_x = s_img->s_player.pos_x;
		s_img->pos_y = s_img->s_player.pos_y;
		put_img(s_img, "images/wall.xpm");
		s_img->pos_y -= 64;
		put_img(s_img, s_img->s_player.path);
		s_img->s_player.y--;
		s_img->s_player.pos_y = s_img->pos_y;
		if (s_img->s_map.map[s_img->s_player.y - 1][s_img->s_player.x] == '0'
				&& control == 0)
			move_u(s_img, keycode, 1);
		else if (s_img->s_player.path[13] == 'L'
			&& s_img->s_map.map[s_img->s_player.y][s_img->s_player.x - 1]
			== '0')
			move_l(s_img, keycode);
		else if (s_img->s_player.path[13] == 'R'
			&& s_img->s_map.map[s_img->s_player.y][s_img->s_player.x + 1]
			== '0')
			move_r(s_img, keycode);
	}
}

int	key_hook(int keycode, t_img *s_img)
{
	steps(s_img);
	if (keycode == 53)
		destroy(s_img);
	else if (keycode == 124 || keycode == 2)
	{
		move_r(s_img, keycode);
		move_sprite(s_img);
	}
	else if (keycode == 123 || keycode == 0)
	{
		move_l(s_img, keycode);
		move_sprite(s_img);
	}
	else if ((keycode == 126 || keycode == 13)
		&& s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] == '1')
	{
		move_u(s_img, keycode, 0);
		move_sprite(s_img);
	}
	return (0);
}
