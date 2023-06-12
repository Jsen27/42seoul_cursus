OBJS		=   ${SRCS:.cpp=.o}

CC			=   c++ -Wall -Wextra -Werror -std=c++98

INCLUDES	=	-I ./includes

RM			=   rm -f

# colors

DEF_COLOR   =   \033[0;39m
CYAN        =   \033[3;96m
GREEN       =   \033[1;92m
MAGENTA     =   \033[3;95m
YELLOW      =   \033[1;93m
BLUE        =   \033[1;94m
GRAY        =   \033[2;90m
WHITE       =   \033[1;97m
RED         =   \033[3;91m

all     :   $(NAME)

%.o     :   %.cpp
			@echo "${GRAY}compiling $<...${DEF_COLOR}"
			@$(CC) $(INCLUDES) -c $< -o $@

$(NAME) :   $(OBJS)
			@$(CC) -o $(NAME) $(OBJS)
			@echo "${YELLOW}All files are compiled !!${DEF_COLOR}"
			@echo "✅ ${GREEN}CPP executable file made !${DEF_COLOR}"

clean   :
			@${RM} ${OBJS}
			@echo "${MAGENTA}object files cleaned !${DEF_COLOR}"

fclean  :   clean
			@${RM} ${NAME}
			@echo "❌${RED}CPP excutable file cleaned !${DEF_COLOR}"
			

re      :   fclean
			@$(MAKE) all
			@echo "${BLUE}Cleaned and Rebuilt all files !${DEF_COLOR}"

.PHONY	:	all clean fclean re .cpp.o
