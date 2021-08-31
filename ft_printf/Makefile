NAME		=	libftprintf.a
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -fr
MK			=	make -C
LIBPATH		=	./libft
AR			=	ar rsc

SRC			=	src/printflags.c src/ft_is_valid.c src/nbr_conversion.c \
				src/ft_print_args.c src/ft_printf.c src/ft_specifier_c.c \
				src/ft_specifier_d_or_i.c src/ft_specifier_p.c src/ft_specifier_s.c \
				src/ft_specifier_u.c src/ft_specifier_x_or_upper_x.c src/utils.c \

OBJ			=	$(SRC:.c=.o)

OBJS		=	printflags.o ft_is_valid.o nbr_conversion.o ft_print_args.o ft_printf.o ft_specifier_c.o \
				ft_specifier_d_or_i.o ft_specifier_p.o ft_specifier_s.o ft_specifier_u.o ft_specifier_x_or_upper_x.o utils.o \

all:		$(NAME)

$(NAME):
	@echo "Compiling Libft [ .. ]"
	@$(MK) $(LIBPATH)
	@echo "Libft is ready! [ OK ]"
	@cp libft/libft.a libftprintf.a
	@echo "Compiling Printf [ .. ]"
	@cc $(FLAGS) -c $(SRC)
	@mv $(OBJS) src
	@$(AR) $(NAME) $(OBJ)
	@echo "Printf is ready! [ OK ]"

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

.PHONY: all, clean, fclean, re