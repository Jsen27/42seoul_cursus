NAME =	a.out

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) a.out
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re
