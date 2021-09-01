CFLAGS		= -Wall -Wextra -Werror
CC			= clang
NAME		= libft.a

SRC			=	ft_itoa.c ft_strchr.c ft_strdup.c ft_strlcpy.c ft_strlen.c \
				ft_toupper.c ft_isdigit.c ft_bzero.c \

OBJ			= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar crs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, bonus
