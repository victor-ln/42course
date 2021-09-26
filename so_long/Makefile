CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
LINKS = -L ./mlx -lmlx -lbsd -lX11 -lXext -lm -lz
INC = -I ./mlx -I ./inc
NAME = so_long

SRC = src/exit.c src/load_map.c src/render.c src/start.c src/utils.c
MAIN = src/main.c

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	make -C ./mlx
	gcc $(FLAGS) $(INC) -c $(SRC)
	gcc $(FLAGS) $(INC) $(OBJ) $(MAIN) ./mlx/libmlx.a $(LINKS) -o $(NAME)

clean:
	make -C ./mlx clean

fclean:
	make -C ./mlx clean

re:			fclean all

bonus:		$(NAME)
