NAME = so_long
MLX = ./minilibx-linux/libmlx.a
LIB = ./libft/libft.a
MAIN = source/main.c
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
LINKS = -lbsd -lX11 -lXext -lz
INC = -I ./minilibx-linux -I ./include -I ./libft

OBJ		=	objects/animations.o \
			objects/end_game.o \
			objects/events.o \
			objects/load_map.o \
			objects/map_init.o \
			objects/map_validate.o \
			objects/render_game.o \
			objects/start_game.o \
			objects/utils.o \

all:		$(NAME)

$(NAME):	mlx_a libft_c
	@make -C ./source
	@clang $(FLAGS) $(INC) $(MAIN) $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game created!"

libft_c:
	@echo "Compiling Libft [ .. ]"
	@make -C ./libft
	@echo "Libft is ready! [ OK ]"

mlx_a:
	@echo "Compiling Mlx [ .. ]"
	@make -C ./minilibx-linux
	@echo "Mlx is ready! [ OK ]"

clean:
	@make -C ./minilibx-linux clean
	@rm -fr objects
	@echo "Object files removed."

fclean:		clean
	@rm $(NAME)
	@echo "Binaries removed."

re:			fclean all

bonus:		$(NAME)

.PHONY: all, clean, fclean, re, message, libft_c