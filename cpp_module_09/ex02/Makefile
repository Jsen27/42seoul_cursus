NAME =	PmergeMe

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic -g

SRCS =	main.cpp \
		PmergeMe.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) PmergeMe
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re
