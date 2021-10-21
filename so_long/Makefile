NAME	= so_long
MLX		= ./mlx/libmlx.a
LIB		= ./libft/libft.a
MAIN	= src/so_long.c
FLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
LINKS	= -lbsd -lX11 -lXext
INC		= -I ./mlx -I ./inc -I ./libft

OBJ		=	obj/animations.o \
			obj/draw_game.o \
			obj/end_game.o \
			obj/events.o \
			obj/load_environment.o \
			obj/load_map.o \
			obj/map_init.o \
			obj/map_validate.o \

all:		$(NAME)

$(NAME):	mlx_a
	@make -C ./libft
	@make -C ./src
	@cc $(FLAGS) $(INC) $(MAIN) $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game created!"

mlx_a:
	@echo "Compiling Mlx [ .. ]"
	@make -C ./mlx
	@echo "Mlx is ready! [ OK ]"

clean:
	@make -C ./mlx clean
	@make -C ./libft clean
	@rm -fr obj
	@echo "Object files removed."

fclean:		clean
	@rm $(NAME)
	@make -C ./libft fclean
	@echo "Binaries removed."

bonus:		mlx_a
	@make -C ./libft bonus
	@make -C ./src bonus
	@cc $(FLAGS) $(INC) $(MAIN) $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game with BONUS created!"

re:			fclean all

.PHONY: all, clean, fclean, bonus, re
