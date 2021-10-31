# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmendes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 15:08:54 by jmendes           #+#    #+#              #
#    Updated: 2021/10/18 11:04:46 by jmendes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc -g
RM		= rm -f

NAME	= so_long
HEADER	= so_long.h
LIBS	= -L./libft -lft
MLX		= /usr/local/lib
FLAGS	= -Wall -Werror -Wextra -g -lmlx -framework OPENGL -framework Appkit -fsanitize=address 

SRC		= so_long.c\
		  movePlayer.c\
		  movePlayer1.c\
		  moveSprite.c\
		  parse.c\
		  subParser.c\
		  gravity.c\
		  error.c\
		  map.c\
		  init.c\
		  get_next_line.c\

%.o:%.c
	$(CC) -o $@ -c $< 

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME) :		$(OBJ) $(HEADER)
	$(MAKE) bonus -C libft
	$(CC) -I . -o $(NAME) $(OBJ) -L $(MLX) $(LIBS) $(FLAGS) 

clean:
		$(RM) $(OBJ)

fclean:	clean
	$(MAKE) fclean -C libft
				$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
