NAME		=	push_swap
BONUS_NAME	=	checker
INC			=	-I ./inc -I ./libft
LIB			=	./libft/libft.a

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -O3 -g3

CHECKER		=	src/checker.c
SORTER		=	src/push_swap.c

FILES		=	check.c \
				end_program.c \
				init_program.c \
				push.c \
				radix_sort.c \
				rotate.c \
				sort_stack.c \
				swap.c \
				utils.c \

SRC			=	$(addprefix ./src/, $(FILES))
OBJ			=	$(addprefix ./obj/, $(FILES:%.c=%.o))

RM			=	rm -fr

$(NAME):	$(LIB)
	$(CC) $(FLAGS) $(INC) -D BONUS=0 -c $(SRC)
	@mkdir -p obj;mv $(notdir $(OBJ)) obj
	$(CC) $(FLAGS) $(INC) $(OBJ) $(SORTER) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C ./libft

clean:
	$(MAKE) -C ./libft clean
	$(RM) ./obj

fclean:		clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re:			fclean	$(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(LIB)
	$(CC) $(FLAGS) $(INC) -D BONUS=1 -c $(SRC)
	@mkdir -p obj;mv $(notdir $(OBJ)) obj
	$(CC) $(FLAGS) $(INC) $(OBJ) $(CHECKER) $(LIB) -o $(BONUS_NAME)

.PHONY: all, clean, fclean, re, bonus