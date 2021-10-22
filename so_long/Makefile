NAME		=	so_long
CC			=	cc
MLX			=	./mlx/libmlx.a
LIB			=	./libft/libft.a
MAIN		=	src/so_long.c
IS_BONUS	=	-D BONUS=1
IS_N_BONUS	=	-D BONUS=0
FLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
LINKS		=	-lbsd -lX11 -lXext
INC			=	-I ./mlx -I ./inc -I ./libft

FILES		=	animations.c \
				draw_game.c \
				end_game.c \
				events.c \
				load_environment.c \
				load_map.c \
				map_init.c \
				map_validate.c \

SRC			=	$(addprefix src/,$(FILES))
OBJ			=	$(addprefix obj/,$(FILES:%.c=%.o))

all:		$(NAME)

$(NAME):	mlx_a
	@echo "Compiling source [ .. ]"
	@$(CC) $(FLAGS) $(INC) $(IS_N_BONUS) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(FILES:%.c=%.o) obj
	@make -C ./libft
	@$(CC) $(FLAGS) $(INC) $(MAIN) -O3 $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game created!"

mlx_a:
	@echo "Compiling Mlx [ .. ]"
	@make -C ./mlx
	@echo "Mlx is ready! [ OK ]"
	@mkdir obj

clean:
	@make -C ./mlx clean
	@make -C ./libft clean
	@rm -fr obj
	@echo "Object files removed."

fclean:		clean
	@rm -f $(NAME)
	@make -C ./libft fclean
	@echo "Binaries removed."

bonus:		mlx_a
	@echo "Compiling source [ .. ]"
	@$(CC) $(FLAGS) $(INC) $(IS_BONUS) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(FILES:%.c=%.o) obj
	@make -C ./libft bonus
	@$(CC) $(FLAGS) $(INC) $(MAIN) -O3 $(OBJ) $(MLX) $(LIB) $(LINKS) -o $(NAME)
	@echo "Game with BONUS created!"

re:			fclean all

.PHONY: all, clean, fclean, bonus, re
