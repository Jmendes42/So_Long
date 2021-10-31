/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveSprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:42:28 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/21 10:58:31 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_sprite_l(t_img *s_img)
{
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x] = '0';
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x - 1] = 'S';
	s_img->pos_x = s_img->s_sprite.pos_x;
	s_img->pos_y = s_img->s_sprite.pos_y;
	put_sprite(s_img, "images/wall.xpm");
	s_img->pos_x -= 64;
	put_sprite(s_img, s_img->s_sprite.path);
	s_img->s_sprite.x--;
	s_img->s_sprite.pos_x = s_img->pos_x;
}

void	move_sprite_r(t_img *s_img)
{
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x] = '0';
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x + 1] = 'S';
	s_img->pos_x = s_img->s_sprite.pos_x;
	s_img->pos_y = s_img->s_sprite.pos_y;
	put_sprite(s_img, "images/wall.xpm");
	s_img->pos_x += 64;
	put_sprite(s_img, s_img->s_sprite.path);
	s_img->s_sprite.x++;
	s_img->s_sprite.pos_x = s_img->pos_x;
}

void	move_sprite_ur(t_img *s_img, int control)
{
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x] = '0';
	s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] = 'S';
	s_img->pos_x = s_img->s_sprite.pos_x;
	s_img->pos_y = s_img->s_sprite.pos_y;
	put_sprite(s_img, "images/wall.xpm");
	s_img->pos_y -= 64;
	put_sprite(s_img, s_img->s_sprite.path);
	s_img->s_sprite.y--;
	s_img->s_sprite.pos_y = s_img->pos_y;
	if (s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] == '0'
			&& control == 0
			&& s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x + 1]
			== '0')
		move_sprite_ur(s_img, 1);
	else if (s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x - 1] == '0')
		move_sprite_r(s_img);
}

void	move_sprite_ul(t_img *s_img, int control)
{
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x] = '0';
	s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] = 'S';
	s_img->pos_x = s_img->s_sprite.pos_x;
	s_img->pos_y = s_img->s_sprite.pos_y;
	put_sprite(s_img, "images/wall.xpm");
	s_img->pos_y -= 64;
	put_sprite(s_img, s_img->s_sprite.path);
	s_img->s_sprite.y--;
	s_img->s_sprite.pos_y = s_img->pos_y;
	if (s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] == '0'
			&& control == 0
			&& s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x - 1]
			== '0')
		move_sprite_ul(s_img, 1);
	else if (s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x - 1] == '0')
		move_sprite_l(s_img);
}

int	move_sprite(t_img *s_img)
{
	if (s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x + 1] == '1'
			&& s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] == '0'
			&& s_img->s_sprite.path[13] == 'R')
		move_sprite_ur(s_img, 0);
	else if (s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x - 1]
			== '1'
			&& s_img->s_map.map[s_img->s_sprite.y - 1][s_img->s_sprite.x] == '0'
			&& s_img->s_sprite.path[13] == 'L')
		move_sprite_ul(s_img, 0);
	else if (s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x - 1] == '0'
			&& s_img->s_map.map[s_img->s_sprite.y + 1][s_img->s_sprite.x] == '1'
			&& s_img->s_sprite.path[13] == 'L')
		move_sprite_l(s_img);
	else if (s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x + 1] == '0'
			&& s_img->s_map.map[s_img->s_sprite.y + 1][s_img->s_sprite.x] == '1'
			&& s_img->s_sprite.path[13] == 'R')
		move_sprite_r(s_img);
	else if (s_img->s_sprite.path[13] == 'R')
		s_img->s_sprite.path = "images/reaperL.xpm";
	else if (s_img->s_sprite.path[13] == 'L')
		s_img->s_sprite.path = "images/reaperR.xpm";
	return (0);
}
