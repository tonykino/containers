NAME		=	containers

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD

SRCS		=	main.cpp test_stack.cpp test_vector.cpp test_rbt.cpp
OBJS		=	$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $? -o $(NAME)

-include $(OBJS:.o=.d)

clean:
	rm -f *.o *.d

fclean: clean
	rm -f $(NAME)

re: fclean all # TODO - Fix this when make -j