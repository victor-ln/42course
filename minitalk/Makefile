NAME		=	server

CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -O3 -g3

INC			=	-I ./inc
LIB_PRINTF	=	./ft_printf/libftprintf.a

SERVER_SRC		=	src/server/server_processes.c \
					src/server/server.c \

CLIENT_SRC		=	src/client/client_processes.c \
					src/client/client.c \

UTILS			=	src/utils.c

CLIENT_OBJ			=	$(addprefix obj/client/, $(notdir $(CLIENT_SRC:%.c=%.o)))
SERVER_OBJ			=	$(addprefix obj/server/, $(notdir $(SERVER_SRC:%.c=%.o)))
UTILS_OBJ		=	$(addprefix obj/, $(notdir $(UTILS:%.c=%.o)))

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(LIB_PRINTF)
	@$(CC) $(FLAGS) $(INC) -c $(CLIENT_SRC) $(SERVER_SRC) $(UTILS)
	@mkdir -p obj obj/client obj/server
	@mv	$(notdir $(CLIENT_SRC:%.c=%.o)) obj/client
	@mv	$(notdir $(SERVER_SRC:%.c=%.o)) obj/server
	@mv	$(notdir $(UTILS:%.c=%.o)) obj
	@$(CC) $(FLAGS) $(INC) $(CLIENT_OBJ) $(UTILS_OBJ) $(LIB_PRINTF) -o client
	@$(CC) $(FLAGS) $(INC) $(SERVER_OBJ) $(UTILS_OBJ) $(LIB_PRINTF) -o server

$(LIB_PRINTF):
	@$(MAKE) -C ./ft_printf

clean:
	@$(MAKE) -C ./ft_printf clean
	@$(RM) obj

fclean:	clean
	@$(MAKE) -C ./ft_printf fclean
	@$(RM) server
	@$(RM) client

re:		fclean	all

bonus:	$(NAME)

norm:
	norminette src inc ft_printf
