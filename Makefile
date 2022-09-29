
CC		= gcc -g
RM		= rm -f

NAME	= so_long
HEADER	= so_long.h
LIBS	= -L./libft -lft
MLX		= /usr/local/lib
FLAGS	= -Wall -Werror -Wextra -g -lmlx -framework OPENGL -framework Appkit -fsanitize=address 

SRC		$(wildcard ./src/*.c)

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
