/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:51:01 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/18 13:00:30 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite(t_img *s_img, char *path)
{
	s_img->img = mlx_xpm_file_to_image(s_img->s_mlx.mlx, path,
			&s_img->width, &s_img->height);
	mlx_put_image_to_window(s_img->s_mlx.mlx, s_img->s_mlx.window,
		s_img->img, s_img->pos_x, s_img->pos_y);
}

void	put_img(t_img *s_img, char *path)
{
	s_img->img = mlx_xpm_file_to_image(s_img->s_mlx.mlx, path,
			&s_img->width, &s_img->height);
	mlx_put_image_to_window(s_img->s_mlx.mlx, s_img->s_mlx.window,
		s_img->img, s_img->pos_x, s_img->pos_y);
}

void	margins(t_img *s_img, int control)
{
	if (control == 0)
	{
		while (s_img->s_map.map[0][s_img->s_map.x] == '1')
		{
			if (!s_img->s_map.map[0][s_img->s_map.x + 1])
				put_img(s_img, "images/grass3.XPM");
			else
				put_img(s_img, "images/grassup.XPM");
			s_img->pos_x += s_img->width;
			s_img->s_map.x++;
		}
	}
	else
	{
		while (s_img->s_map.map[s_img->s_map.y][s_img->s_map.x] == '1')
		{
			if (!s_img->s_map.map[s_img->s_map.y][s_img->s_map.x + 1])
				put_img(s_img, "images/grass4.XPM");
			else
				put_img(s_img, "images/grassdown.XPM");
			s_img->pos_x += s_img->width;
			s_img->s_map.x++;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_img	s_img;

	if (argc != 2)
	{
		printf("ERROR: WRONG NUMBER OF ARGS\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "map.ber", 7) != 0)
		error(&s_img, "WRONG MAP NAME");
	init_img(&s_img);
	open_map(&s_img);
	s_img.s_mlx.mlx = mlx_init();
	s_img.s_mlx.window = mlx_new_window(s_img.s_mlx.mlx, s_img.s_map.max_x * 64,
			s_img.s_map.max_y * 64, "Hello World");
	parser(&s_img);
	mlx_loop_hook(s_img.s_mlx.mlx, &gravity, &s_img);
	mlx_hook(s_img.s_mlx.window, 2, 1L << 0, key_hook, &s_img);
	mlx_hook(s_img.s_mlx.window, 17, 1L << 17, destroy1, &s_img);
	mlx_loop(s_img.s_mlx.mlx);
}
