NAME = phonebook

CXX = c++ 

CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS = 	PhoneBook.cpp Contact.cpp main.cpp

HEADERS = PhoneBook.hpp Contact.hpp

SRCS_OBJ = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	$(CXX) $(CFLAGS) $(SRCS_OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	rm -f ${SRCS_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re