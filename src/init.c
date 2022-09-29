/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:45:38 by jmendes           #+#    #+#             */
/*   Updated: 2022/09/29 03:16:09 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map1(t_img *s_img, t_list *list)
{
	s_img->s_map.y = 0;
	s_img->s_map.x = 0;
	s_img->s_map.exitx = 0;
	s_img->s_map.exity = 0;
	s_img->s_map.max_x = 0;
	s_img->s_map.error_c = 0;
	s_img->s_map.error_p = 0;
	s_img->s_map.error_e = 0;
	s_img->s_map.max_y = ft_lstsize(list) - 1;
}

void	init_map(t_img *s_img, t_list *list)
{
	int	index;
	int	index1;

	index = 0;
	init_map1(s_img, list);
	s_img->s_map.map = ft_calloc(s_img->s_map.max_y + 1, sizeof(char *));
	while (list)
	{
		s_img->s_map.map[index] = list->content;
		list = list->next;
		index++;
	}
	s_img->s_map.map[index] = NULL;
	index = 0;
	while (s_img->s_map.map[0][s_img->s_map.max_x])
		s_img->s_map.max_x++;
}

void	init_player(t_img *s_img)
{
	s_img->s_player.steps = NULL;
	s_img->s_player.y = 0;
	s_img->s_player.x = 0;
	s_img->s_player.control = 0;
	s_img->s_player.pos_y = 0;
	s_img->s_player.pos_x = 0;
	s_img->s_player.width = 0;
	s_img->s_player.height = 0;
	s_img->s_player.img = 0;
	s_img->s_player.path = "../images/chompyR.xpm";
}

void	init_sprite(t_img *s_img)
{
	s_img->s_sprite.y = 0;
	s_img->s_sprite.x = 0;
	s_img->s_sprite.pos_y = 0;
	s_img->s_sprite.pos_x = 0;
	s_img->s_sprite.width = 0;
	s_img->s_sprite.height = 0;
	s_img->s_sprite.img = 0;
	s_img->s_sprite.path = "../images/reaperL.xpm";
}

void	init_img(t_img *s_img)
{
	s_img->y = 0;
	s_img->x = 0;
	s_img->c = 0;
	s_img->max_c = 0;
	s_img->img = 0;
	s_img->pos_y = 0;
	s_img->pos_x = 0;
	s_img->width = 0;
	s_img->height = 0;
	init_player(s_img);
	init_sprite(s_img);
}
