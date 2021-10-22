FLAGS		= -Wall -Wextra -Werror

CC			= cc

NAME		= libft.a

SRC			=	ft_bzero.c ft_calloc.c ft_putendl_fd.c \
				ft_strdup.c ft_strjoin.c ft_strlen.c \
				ft_strcmp.c ft_utoa.c ft_rand.c \

BONUS		=	ft_delay.c \

BONUS_OBJ	= $(BONUS:.c=.o)

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@echo "Compiling Libft [ .. ]"
	@$(CC) $(FLAGS) -O3 -c $(SRC)
	@ar crs $(NAME) $(OBJ)
	@mkdir obj
	@mv $(OBJ) obj
	@echo "Libft is ready! [ OK ]"

clean:
	@rm -fr ./obj

fclean:		clean
	@rm -fr $(NAME)

re:	fclean all

bonus:		
	@echo "Compiling Libft [ .. ]"
	@$(CC) $(FLAGS) -c $(SRC) $(BONUS)
	@ar crs $(NAME) $(OBJ) $(BONUS_OBJ)
	@mkdir obj
	@mv $(OBJ) $(BONUS_OBJ) obj
	@echo "Libft with BONUS is ready! [ OK ]"

.PHONY: all, clean, fclean, re, bonus
