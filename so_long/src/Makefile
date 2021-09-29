FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

LINKS = -lbsd -lX11 -lXext -lm -lz

INC = -I ../mlx -I ../inc -I ../libft

SRC = ft_load_map.c ft_render.c ft_start_game.c ft_utils.c \

OBJ = $(SRC:.c=.o)

all:
	@clang $(FLAGS) $(INC) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)