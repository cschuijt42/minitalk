CLIENT_OBJ    := client.o
SERVER_OBJ    := server.o
CFLAGS        := -Werror -Wall -Wextra -g -I lib/libft
LIBFT_A       := lib/libft/libft.a
NAME          := minitalk
CLIENT        := client
SERVER        := server

$(NAME) : all

$(CLIENT) : $(CLIENT_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT_A)

$(SERVER) : $(SERVER_OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT_A)

all : $(CLIENT) $(SERVER)

re : fclean all

clean :
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean :
	rm -f $(CLIENT) $(SERVER) $(CLIENT_OBJ) $(SERVER_OBJ)

$(LIBFT_A) : lib/libft/libft.h
	make -C lib/libft

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY : clean fclean re
