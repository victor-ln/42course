FLAGS		= -Wall -Wextra -Werror -g3 -O3
CC			= clang
NAME		= libft.a

SRC			=	ft_itoa.c ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
				ft_toupper.c ft_isdigit.c ft_bzero.c ft_strcmp.c \

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC)
	@ar crs $(NAME) $(OBJ)
	@mkdir -p obj
	@mv $(OBJ) obj

clean:
	@rm -rf ./obj

fclean:		clean
	@rm -fr $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
