NAME = Animal

CXX = c++ 

CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

HEADERS = Brain.hpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

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