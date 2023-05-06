NAME =	convert

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS =	main.cpp \
		ScalarConverter.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) convert
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re
