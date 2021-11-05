NAME		=	server

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -O3 -g3

INC			=	-I ./inc
LIB_PRINTF	=	./ft_printf/libftprintf.a

OBJ_S		=	$(addprefix obj/, $(notdir $(SRC_S:%.c=%.o)))
OBJ_C		=	$(addprefix obj/, $(notdir $(SRC_C:%.c=%.o)))

RM			=	rm -rf
SAFE_MKDIR	=	mkdir -p

all:		$(NAME)

$(NAME):	$(LIB_PRINTF)
	$(CC) $(FLAGS) $(INC) src/client.c $(LIB_PRINTF) -o client
	$(CC) $(FLAGS) $(INC) src/server.c $(LIB_PRINTF) -o server

$(LIB_PRINTF):
	$(MAKE) -C ./ft_printf

clean:
	$(MAKE) -C ./ft_printf clean
	$(RM) $(OBJ)

fclean:
	$(MAKE) -C ./ft_printf fclean
	$(RM) server
	$(RM) client

re:		fclean	all

bonus:	$(NAME)

norm:
	norminette src inc ft_printf
