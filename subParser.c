/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subParser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:05:07 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/16 13:13:06 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sub_parser4(t_img *s_img)
{
	put_img(s_img, "images/wall.xpm");
	put_img(s_img, "images/reaperL.XPM");
	s_img->s_sprite.x = s_img->s_map.x;
	s_img->s_sprite.y = s_img->s_map.y;
	s_img->s_sprite.pos_x = s_img->pos_x;
	s_img->s_sprite.pos_y = s_img->pos_y;
}

void	sub_parser3(t_img *s_img)
{
	put_img(s_img, "images/wall.xpm");
	put_img(s_img, "images/vaca.xpm");
	s_img->s_map.error_c++;
	s_img->max_c++;
}

void	sub_parser2(t_img *s_img)
{
	put_img(s_img, "images/wall.xpm");
	put_img(s_img, "images/chompyR.xpm");
	s_img->s_player.pos_y = s_img->pos_y;
	s_img->s_player.pos_x = s_img->pos_x;
	s_img->s_player.y = s_img->s_map.y;
	s_img->s_player.x = s_img->s_map.x;
	s_img->s_map.error_p++;
}

void	sub_parser1(t_img *s_img)
{
	put_img(s_img, "images/wall.xpm");
	put_img(s_img, "images/door.xpm");
	s_img->s_map.exitx = s_img->pos_x;
	s_img->s_map.exity = s_img->pos_y;
	s_img->s_map.error_e++;
}
