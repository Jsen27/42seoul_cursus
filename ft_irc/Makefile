NAME	=	ircserv

CXX 	= 	c++ -Wall -Wextra -Werror -std=c++98

SRCS 	=	src/ircserv.cpp\
			src/Command.cpp\
			src/Server.cpp

OBJS 	=	$(SRCS:.cpp=.o)

# colors
END		=	\033[0;39m
GREEN	=	\033[0;92m
RED		=	\033[0;91m
YELLOW	=	\033[0;93m
GRAY	=	\033[0;90m

all		:	$(NAME)

%.o		:	%.cpp
			@echo "$(GRAY)Compiling $<...$(END)"
			@$(CXX) -c $< -o $@

$(NAME)	:	$(OBJS)
			@$(CXX) -o $(NAME) $(OBJS)
			@echo "All files are compiled !"
			@echo "$(GREEN)✅Excutable file made !!$(END)"

clean	:
			@echo "$(RED)❌Object files cleaned !$(END)"
			@$(RM) $(OBJS)

fclean	:	clean
			@echo "$(RED)❌Excutable file cleaned !$(END)"
			@$(RM) $(NAME)

re		:	fclean
			@$(MAKE) all
			@echo "$(YELLOW)🍋Cleaned and Rebuilt all files !$(END)"

.PHONY	:	all clean fclean re
