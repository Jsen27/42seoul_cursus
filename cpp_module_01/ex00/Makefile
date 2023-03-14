NAME =	BraiiiiiiinnnzzzZ

CXX = c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) BraiiiiiiinnnzzzZ
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re