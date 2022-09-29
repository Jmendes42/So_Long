/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movePlayer1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:34:01 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/29 03:16:27 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_r1(t_img *s_img)
{
	s_img->s_map.map[s_img->s_player.y][s_img->s_player.x] = '0';
	s_img->pos_x = s_img->s_player.pos_x;
	s_img->pos_y = s_img->s_player.pos_y;
	put_img(s_img, "../images/wall.xpm");
	s_img->pos_x += 64;
	put_img(s_img, s_img->s_player.path);
	s_img->s_player.x++;
	s_img->s_player.pos_x = s_img->pos_x;
}

void	move_l1(t_img *s_img)
{
	s_img->s_map.map[s_img->s_player.y][s_img->s_player.x] = '0';
	s_img->pos_x = s_img->s_player.pos_x;
	s_img->pos_y = s_img->s_player.pos_y;
	put_img(s_img, "../images/wall.xpm");
	s_img->pos_x -= 64;
	put_img(s_img, s_img->s_player.path);
	s_img->s_player.x--;
	s_img->s_player.pos_x = s_img->pos_x;
}
