SRC=main.cpp fraction.cpp simplification.cpp

OBJ=$(subst .cpp,.o,$(SRC))

NAME= tp3

ALL= $(CC)

CXXFLAGS= -std=c++11 -Wall -Wextra -I.

$(CC):$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(ALL)
