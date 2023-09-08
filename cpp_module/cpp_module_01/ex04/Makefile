NAME =	Sed_is_for_losers

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) Sed_is_for_losers
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re