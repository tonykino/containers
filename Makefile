NAME		=	containers

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD

SRCS		=	$(addprefix tester/, main.cpp test_map.cpp test_stack.cpp test_vector.cpp)
OBJS		=	$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $? -o $(NAME)

-include $(OBJS:.o=.d)

clean:
	rm -f *.o *.d
	rm tester/*.d tester/*.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all