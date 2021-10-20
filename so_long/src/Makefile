FLAGS	=	-Wall -Werror -Wextra -g3
INC		=	-I ../mlx -I ../inc -I ../libft

SRC		=	animations.c \
			draw_game.c \
			end_game.c \
			events.c \
			load_environment.c \
			load_game.c \
			load_map.c \
			map_init.c \
			map_validate.c \

OBJS	=	$(SRC:.c=.o)

all:
	@mkdir ../obj
	@echo "Compiling source [ .. ]"
	@clang $(FLAGS) $(INC) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(OBJS) ../obj
