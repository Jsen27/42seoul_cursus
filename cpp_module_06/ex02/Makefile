NAME =	serializer

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS =	main.cpp \
		Serializer.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) serializer
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re
