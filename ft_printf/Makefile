NAME		=	libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
CC			= 	clang
RM			=	rm -fr
MK			=	make -C
LIBPATH		=	./libft
AR			=	ar rsc

SRC			=	src/printflags.c src/ft_is_valid.c src/nbr_conversion.c \
				src/ft_print_args.c src/ft_printf.c specifiers/ft_specifier_c.c \
				specifiers/ft_specifier_d_or_i.c specifiers/ft_specifier_p.c specifiers/ft_specifier_s.c \
				specifiers/ft_specifier_u.c specifiers/ft_specifier_x_or_upper_x.c src/utils.c \

OBJ			=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	libft_c message $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "Printf is ready! [ OK ]"

message:
	@echo "Compiling Printf [ .. ]"

libft_c:
	@echo "Compiling Libft [ .. ]"
	@$(MK) $(LIBPATH)
	@echo "Libft is ready! [ OK ]"
	@cp libft/libft.a libftprintf.a

clean:
	@$(RM) $(OBJ)
	@$(MK) $(LIBPATH) clean
	@echo "Object files removed."

fclean:		clean
	@$(RM) $(NAME)
	@$(MK) $(LIBPATH) fclean
	@echo "Binaries removed."

bonus:		all

re:			fclean all

.PHONY: all, clean, fclean, re, message, libft_c