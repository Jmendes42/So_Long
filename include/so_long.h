/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:26:57 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/17 19:27:42 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
	int		max_y;
	int		max_x;
	int		exitx;
	int		exity;
	int		error_c;
	int		error_p;
	int		error_e;
}				t_map;	

typedef struct s_sprite
{
	int		y;
	int		x;
	int		pos_y;
	int		pos_x;
	int		width;
	int		height;
	char	*path;
	void	*img;
}			t_sprite;

typedef struct s_player
{
	int		y;
	int		x;
	int		control;
	int		pos_y;
	int		pos_x;
	int		width;
	int		height;
	char	*steps;
	char	*path;
	void	*img;
}					t_img1;

typedef struct s_img
{
	int			y;
	int			x;
	int			pos_y;
	int			pos_x;
	int			width;
	int			height;
	int			c;
	int			max_c;
	void		*img;
	t_map		s_map;
	t_mlx		s_mlx;
	t_img1		s_player;
	t_sprite	s_sprite;
}				t_img;

int		get_next_line(int fd, char **line);

//SOLONG
void	put_img(t_img *s_img, char *path);
void	margins(t_img *s_img, int control);
void	put_sprite(t_img *s_img, char *path);

//GRAVITY
void	steps(t_img *s_img);
int		gravity(t_img *s_img);

//PARSER
void	parser(t_img *s_img);

//SUB PARSER
void	sub_parser1(t_img *s_img);
void	sub_parser2(t_img *s_img);
void	sub_parser3(t_img *s_img);
void	sub_parser4(t_img *s_img);

//INIT
void	init_img(t_img *s_img);
void	init_player(t_img *s_img);
void	init_map(t_img *s_img, t_list *list);

//ERROR
void	destroy(t_img *s_img);
int		destroy1(t_img *s_img);
void	error(t_img *s_img, char *message);

//MAP
int		open_map(t_img *s_img);
void	map_error(t_img *s_img);

//MOVE PLAYER
int		key_hook(int keycode, t_img *s_img);

//MOVE PLAYER 1
void	move_r1(t_img *s_img);
void	move_l1(t_img *s_img);

//MOVE SPRITE
int		move_sprite(t_img *s_img);

#endif
