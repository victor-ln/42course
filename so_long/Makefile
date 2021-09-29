NAME = so_long
MLX = ./mlx/libmlx.a
LIB = ./libft/libft.a
MAIN = ./src/core.c
FLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
LINKS = -lbsd -lX11 -lXext -lm -lz
INC = -I ./mlx -I ./libft -I ./inc
OBJ = src/exit.o src/ft_load_map.o src/ft_render.o src/ft_start_game.o src/ft_utils.o

all:		$(NAME)

$(NAME):	libft_a mlx_a src_a
	@clang $(FLAGS) $(INC) $(MAIN) $(OBJ) $(LIB) $(MLX) $(LINKS) -o $(NAME)

libft_a:
	@echo "Compiling Libft [ .. ]"
	@make -C ./libft
	@echo "Libft is ready! [ OK ]"

mlx_a:
	@echo "Compiling Mlx [ .. ]"
	@make -C ./mlx
	@echo "Mlx is ready! [ OK ]"

src_a:
	@echo "Compiling Source [ .. ]"
	@make -C ./src all
	@echo "Source compiled! [ OK ]"

clean:
	@make -C ./src clean
	@make -C ./mlx clean
	@make -C ./libft clean
	@echo "Object files removed."

fclean:	clean
	@make -C ./src fclean
	@make -C ./libft fclean
	@rm $(NAME)
	@echo "Binaries removed."

re:			fclean all

bonus:		$(NAME)

.PHONY: all, clean, fclean, re, message, libft_c
