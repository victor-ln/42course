FLAGS		= -Wall -Wextra -Werror

NAME		= libft.a

SRC			=	ft_bzero.c ft_calloc.c ft_putendl_fd.c \
				ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c \
				ft_strcmp.c ft_utoa.c \

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			gcc $(FLAGS) -c $(SRC)
			ar crs $(NAME) $(OBJ)

clean:
			rm -f $(OBJ) $(BONUS_OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
