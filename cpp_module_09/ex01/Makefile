NAME =	RPN

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic -g

SRCS =	main.cpp \
		RPN.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) btc
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re
