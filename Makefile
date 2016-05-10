# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 16:38:05 by aputman           #+#    #+#              #
#    Updated: 2016/05/03 15:58:41 by aputman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

SRC =	fdf.c\
		getmap.c\
		mlx.c\
		printmap.c\
		projection.c\
		error.c\
		keycode.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror -Ofast

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) -lmlx -framework AppKit -framework OpenGL

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
