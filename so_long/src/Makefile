FLAGS	=	-Wall -Werror -Wextra -g3
IS_BONUS = -D BONUS=1
IS_N_BONUS = -D BONUS=0
INC		=	-I ../mlx -I ../inc -I ../libft

SRC		=	animations.c \
			draw_game.c \
			end_game.c \
			events.c \
			load_environment.c \
			load_map.c \
			map_init.c \
			map_validate.c \

OBJS	=	$(SRC:.c=.o)

all:
	@mkdir ../obj
	@echo "Compiling source [ .. ]"
	@cc $(FLAGS) $(INC) $(IS_N_BONUS) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(OBJS) ../obj

bonus:
	@mkdir ../obj
	@echo "Compiling source [ .. ]"
	@cc $(FLAGS) $(INC) $(IS_BONUS) -c $(SRC)
	@echo "Source compiled! [ OK ]"
	@mv $(OBJS) ../obj
