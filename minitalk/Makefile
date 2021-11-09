NAME		=	server

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -O3 -g3

INC			=	-I ./inc
LIB_PRINTF	=	./ft_printf/libftprintf.a

CLIENT		=	./src/client/client.c \
				./src/client/client_utils.c \

SERVER		=	./src/server/server.c

SRC			=	src/error.c
OBJ			=	src/error.o

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(LIB_PRINTF)
	@$(CC) $(FLAGS) $(INC) -c $(SRC)
	@mv	$(notdir $(OBJ)) ./src
	@$(CC) $(FLAGS) $(INC) $(CLIENT) $(OBJ) $(LIB_PRINTF) -o client
	@$(CC) $(FLAGS) $(INC) $(SERVER) $(OBJ) $(LIB_PRINTF) -o server

$(LIB_PRINTF):
	@$(MAKE) -C ./ft_printf

clean:
	@$(MAKE) -C ./ft_printf clean
	@$(RM) $(OBJ)

fclean:	clean
	@$(MAKE) -C ./ft_printf fclean
	@$(RM) server
	@$(RM) client

re:		fclean	all

bonus:	$(NAME)

norm:
	norminette src inc ft_printf
