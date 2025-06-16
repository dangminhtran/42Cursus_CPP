NAME = weapon

CXX = c++ 

CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

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
