##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for rush2
##



CXXFLAGS	=	-I./include/ -I./include/chipsets -std=gnu++11 -W -Wall -Wextra -g3

CC = 	g++
	
SRC_M	=	src/chipsets/c4081.cpp		\
			src/chipsets/c4013.cpp		\
			src/chipsets/c4001.cpp		\
			src/chipsets/c4008.cpp		\
			src/chipsets/c4011.cpp		\
			src/chipsets/c4030.cpp		\
			src/chipsets/c4071.cpp		\
			src/chipsets/c4069.cpp		\
			src/chipsets/c4040.cpp		\
			src/chipsets/c4094.cpp		\
			src/chipsets/c4017.cpp		\
			src/chipsets/c4514.cpp		\
			src/chipsets/FlipFlop.cpp	\
			src/chipsets/input.cpp		\
			src/chipsets/output.cpp		\
			src/chipsets/ctrue.cpp		\
			src/chipsets/cfalse.cpp		\
			src/chipsets/cclock.cpp		\
			src/AComponent.cpp			\
			src/Circuit.cpp				\
			src/createPin.cpp			\
			src/Gate.cpp				\
			src/error.cpp			\
			src/parsing.cpp			\
			src/readFile.cpp		\
			src/word_array.cpp		\
			src/size_array.cpp		\
			src/Factory.cpp			\
			src/prompt.cpp			\
			src/nbr_base_to_str.cpp	\

SRC_T	=	tests/TestU_deserializer.cpp

SRC_O	=	src/main.cpp

OBJ	=	$(SRC_M:.cpp=.o)

OBJ_T 	=	$(SRC_T:.cpp=.o)

OBJ_O	=	$(SRC_O:.cpp=.o)

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_O)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_O) $(CXXFLAGS)

test_run: CXXFLAGS += --coverage
test_run:	$(OBJ_T) $(OBJ)
	$(CC) -o $(NAME)  $(OBJ) $(OBJ_T) $(CXXFLAGS) -lcriterion
	./$(NAME)
	gcovr -r . --html -o coverage.html --html-details -e "tests"

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_T)
	rm -f $(OBJ_O)

fclean:	clean
	rm -f $(NAME)
	find . -name "*.gcda" -type f -delete
	find . -name "*.html" -type f -delete
	find . -name "*.gcno" -type f -delete

re:	fclean all