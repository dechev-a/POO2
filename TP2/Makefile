SRC=main.cpp file_manage.cpp 

OBJ=$(subst .cpp,.o,$(SRC))

NAME= tp2

ALL= $(CC)

CXXFLAGS= -std=c++11 -Wall -Wextra

$(CC):$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(ALL)
