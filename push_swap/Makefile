NAME		=	push_swap
INC			=	-I ./inc -I ./libft
LIB			=	./libft/libft.a

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -O3 -g3

FILES		=	check_stack.c \
				end_program.c \
				push_stack.c \
				push_swap.c \
				rotate_stack.c \
				start_stack.c \
				swap_stack.c \

SRC			=	$(addprefix ./src/, $(FILES))
OBJ			=	$(addprefix ./obj/, $(FILES:%.c=%.o))

RM			=	rm -fr

$(NAME):	$(LIB)
	$(CC) $(FLAGS) $(INC) -c $(SRC)
	@mkdir -p obj;mv $(notdir $(OBJ)) obj
	$(CC) $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	$(MAKE) -C ./libft

clean:
	$(MAKE) -C ./libft clean
	$(RM) ./obj

fclean:		clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re:			fclean	$(NAME)

bonus:		$(NAME)

.PHONY: all, clean, fclean, re, bonus