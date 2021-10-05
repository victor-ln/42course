NAME = so_long
MLX = ./minilibx-linux/libmlx.a
MAIN = source/main.c
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
LINKS = -lbsd -lX11 -lXext -lm -lz
INC = -I ./minilibx-linux -I ./include
OBJ = objects/exit.o objects/events.o objects/validation.o objects/render_game.o objects/start_game.o objects/utils.o
SRC = source/exit.c source/events.c source/validation.c source/render_game.c source/start_game.c source/utils.c

all:		$(NAME)

$(NAME):	mlx_a
	@echo "Compiling source [ .. ]"
	@clang $(FLAGS) -c $(SRC) $(INC)
	@echo "Source compiled! [ OK ]"
	@mkdir objects
	@mv *.o objects
	@clang $(FLAGS) $(INC) $(MAIN) $(OBJ) $(MLX) $(LINKS) -o $(NAME)
	@echo "Game created!"

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