NAME = so_long
MLX = ./mlx/libmlx.a
LIB = ./libft/libft.a
MAIN = src/so_long.c
FLAGS = -Wall -Werror -Wextra -g3
LINKS = -lbsd -lX11 -lXext -lz
INC = -I ./mlx -I ./inc -I ./libft

OBJ		=	obj/animations.o \
			obj/draw_game.o \
			obj/end_game.o \
			obj/events.o \
			obj/load_game.o \
			obj/load_map.o \
			obj/map_init.o \
			obj/map_validate.o \

all:		$(NAME)

$(NAME):	mlx_a libft_c
	@make -C ./src
	@clang $(FLAGS) $(INC) $(MAIN) $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game created!"

libft_c:
	@echo "Compiling Libft [ .. ]"
	@make -C ./libft
	@echo "Libft is ready! [ OK ]"

mlx_a:
	@echo "Compiling Mlx [ .. ]"
	@make -C ./mlx
	@echo "Mlx is ready! [ OK ]"

clean:
	@make -C ./mlx clean
	@make -C ./libft clean
	@rm -fr objects
	@echo "Object files removed."

fclean:		clean
	@rm $(NAME)
	@make -C ./libft fclean
	@echo "Binaries removed."

re:			fclean all

bonus:		$(NAME)

.PHONY: all, clean, fclean, re, message, libft_c