NAME =	PhoneBook

CXX = g++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp \

OBJS =	$(SRCS:.cpp=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

clean	:
			$(RM) $(OBJS)

fclean	:	
			$(RM) $(OBJS) PhoneBook
			
re	:	fclean
		make all

.PHONY	:	all clean fclean re