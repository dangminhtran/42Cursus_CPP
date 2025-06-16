# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 11:58:10 by dangtran          #+#    #+#              #
#    Updated: 2025/04/27 11:58:11 by dangtran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

CXX = c++ 

CFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp Fixed.cpp

HEADERS = Fixed.hpp

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