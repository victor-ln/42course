FLAGS		=	-Wall -Wextra -Werror -O3 -g3
CC			=	clang
NAME		=	libft.a

SRC			=	ft_bzero.c ft_calloc.c ft_isdigit.c \
				ft_memcpy.c ft_memmove.c ft_putstr_fd.c \
				ft_strchr.c ft_strlen.c ft_strcmp.c \

OBJ			=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	@mkdir -p obj/
	$(CC) $(FLAGS) -c $(SRC)
	ar crs $(NAME) $(OBJ)
	mv $(OBJ) obj/

clean:
	rm -rf obj/

fclean:		clean
	rm -fr $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re
