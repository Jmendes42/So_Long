/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:57:10 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/17 18:31:16 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gravity2(t_img *s_img)
{
	s_img->pos_x = s_img->s_sprite.pos_x;
	s_img->pos_y = s_img->s_sprite.pos_y;
	s_img->s_map.map[s_img->s_sprite.y][s_img->s_sprite.x] = '0';
	s_img->s_map.map[s_img->s_sprite.y + 1][s_img->s_sprite.x] = 'S';
	put_img(s_img, "images/wall.xpm");
	s_img->pos_y += 64;
	usleep(200000);
	put_sprite(s_img, s_img->s_sprite.path);
	s_img->s_sprite.y++;
	s_img->s_sprite.pos_y = s_img->pos_y;
}

void	gravity1(t_img *s_img)
{
	if (s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] == 'S')
		destroy(s_img);
	s_img->pos_x = s_img->s_player.pos_x;
	s_img->pos_y = s_img->s_player.pos_y;
	if (s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] == 'C')
		s_img->c++;
	s_img->s_map.map[s_img->s_player.y][s_img->s_player.x] = '0';
	s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] = 'P';
	put_img(s_img, "images/wall.xpm");
	s_img->pos_y += 64;
	usleep(200000);
	put_img(s_img, s_img->s_player.path);
	s_img->s_player.y++;
	s_img->s_player.pos_y = s_img->pos_y;
}

int	gravity(t_img *s_img)
{
	if ((s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] == '0'
		|| s_img->s_map.map[s_img->s_player.y + 1][s_img->s_player.x] == 'C'))
		gravity1(s_img);
	if ((s_img->s_map.map[s_img->s_sprite.y + 1][s_img->s_sprite.x] == '0'
		|| s_img->s_map.map[s_img->s_sprite.y + 1][s_img->s_sprite.x] == 'C'))
		gravity2(s_img);
	if (s_img->c == s_img->max_c)
	{
		s_img->pos_x = s_img->s_map.exitx;
		s_img->pos_y = s_img->s_map.exity;
		put_img(s_img, "images/wall.xpm");
		put_img(s_img, "images/door_open.xpm");
	}
	return (0);
}

void	steps(t_img *s_img)
{
	s_img->s_player.control++;
	s_img->s_player.steps = ft_itoa(s_img->s_player.control);
	s_img->pos_y = 64;
	s_img->pos_x = 64;
	put_img(s_img, "images/wall.xpm");
	mlx_string_put(s_img->s_mlx.mlx, s_img->s_mlx.window,
		64, 64, 0x000000, s_img->s_player.steps);
}
