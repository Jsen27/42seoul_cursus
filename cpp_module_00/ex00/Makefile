NAME =	megaphone

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	megaphone.cpp\

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) megaphone

re	:	fclean
		make all

.PHONY	:	all clean fclean re