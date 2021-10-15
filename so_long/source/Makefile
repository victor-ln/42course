FLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3
INC		=	-I ../minilibx-linux -I ../include -I ../libft

SRC		=	animations.c \
			end_game.c \
			events.c \
			load_map.c \
			map_init.c \
			map_validate.c \
			render_game.c \
			start_game.c \
			utils.c \

OBJS	=	$(SRC:.c=.o)

all:
	@mkdir ../objects
	@echo "Compiling source [ .. ]"
	@clang $(FLAGS) $(INC) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(OBJS) ../objects
