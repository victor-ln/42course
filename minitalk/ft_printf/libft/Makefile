FLAGS		= -Wall -Wextra -Werror -g3 -O3
CC			= clang
NAME		= libft.a

SRC			=	ft_bzero.c \
				ft_isdigit.c \
				ft_itoa.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_toupper.c \

INC			=	-I ../../inc
OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(INC) -c $(SRC)
	@ar crs $(NAME) $(OBJ)
	@mkdir -p obj
	@mv $(OBJ) obj

clean:
	@rm -rf ./obj

fclean:		clean
	@rm -fr $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
