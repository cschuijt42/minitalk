CLIENT_OBJ    := 
SERVER_OBJ    := 
CFLAGS        := -Werror -Wall -Wextra -g -I lib
LIBFT_A       := lib/libft/libft.a
CLIENT_HEADER := minitalk_client.h
SERVER_HEADER := minitalk_server.h
NAME          := minitalk
CLIENT        := client
SERVER        := server

$(NAME) : all

$(CLIENT) : $(CLIENT_OBJ) $(LIBFT_A) $(CLIENT_HEADER)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT_A)

$(SERVER) : $(SERVER_OBJ) $(LIBFT_A) $(SERVER_HEADER)
	$(CC) $(CFLAGS) -o $(CLIENT) $(SERVER_OBJ) $(LIBFT_A)

all : $(CLIENT) $(SERVER)

re : fclean all

clean :
	rm -f $(OBJFILES)

fclean :
	rm -f $(NAME) $(OBJFILES)

$(LIBFT_A) : lib/libft/libft.h
	make -C lib/libft

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY : clean fclean re
