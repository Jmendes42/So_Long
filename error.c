/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:55:23 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/17 19:30:07 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_img *s_img, char *message)
{
	int	index;

	index = 0;
	printf("ERROR: %s\n", message);
	if (s_img->s_map.map)
	{
		while (index < s_img->s_map.max_y)
		{
			free(s_img->s_map.map[index]);
			index++;
		}
		free(s_img->s_map.map);
	}
	exit(0);
}

void	destroy(t_img *s_img)
{
	int	index;

	index = 0;
	mlx_destroy_window(s_img->s_mlx.mlx, s_img->s_mlx.window);
	free(s_img->img);
	while (index < s_img->s_map.max_y)
	{
		free(s_img->s_map.map[index]);
		index++;
	}
	free(s_img->s_map.map);
	exit(0);
}

int	destroy1(t_img *s_img)
{
	int	index;

	index = 0;
	mlx_destroy_window(s_img->s_mlx.mlx, s_img->s_mlx.window);
	free(s_img->img);
	while (index < s_img->s_map.max_y)
	{
		free(s_img->s_map.map[index]);
		index++;
	}
	free(s_img->s_map.map);
	exit(0);
}
