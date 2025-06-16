NAME = megaphone

CC = c++ 

CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS_DIR = 	megaphone.cpp

SRCS_OBJ = ${SRCS_DIR:.cpp=.o}

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	$(CC) $(CFLAGS) $(SRCS_OBJ) -o $(NAME)

clean :
	rm -f ${SRCS_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re