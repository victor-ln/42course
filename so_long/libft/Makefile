FLAGS		= -Wall -Wextra -Werror

NAME		= libft.a

SRC			=	ft_bzero.c ft_calloc.c ft_putendl_fd.c \
				ft_strdup.c ft_strjoin.c ft_strlen.c \
				ft_strcmp.c ft_utoa.c \

BONUS		=	ft_delay.c ft_rand.c \

BONUS_OBJ	= $(BONUS:.c=.o)

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			@echo "Compiling Libft [ .. ]"
			cc $(FLAGS) -c $(SRC)
			ar crs $(NAME) $(OBJ)
			@echo "Libft is ready! [ OK ]"

clean:
			rm -f $(OBJ) $(BONUS_OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

bonus:		
			@echo "Compiling Libft [ .. ]"
			cc $(FLAGS) -c $(SRC) $(BONUS)
			ar crs $(NAME) $(OBJ) $(BONUS_OBJ)
			@echo "Libft with BONUS is ready! [ OK ]"

.PHONY: all, clean, fclean, re, bonus
