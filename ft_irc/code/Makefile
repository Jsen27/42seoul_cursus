# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 21:11:43 by ifanzilka         #+#    #+#              #
#    Updated: 2022/09/28 05:33:04 by ifanzilka        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## HELPER

## USE nc: nc 127.0.0.1 port 


CXX = clang++

#Compilation flag
CPPFLAGS = -Wall -Wextra -Werror #-std=c++98

INCLUDES = includes

SRCS = srcs/ServerApi.cpp srcs/IrcServer.cpp srcs/utility.cpp srcs/IrcServerCommands.cpp srcs/Channel.cpp 

SELECT_SRCS = srcs/ServerSelect.cpp

POLL_SRCS = srcs/ServerPoll.cpp

EPOLL_SRCS = srcs/ServerEpoll.cpp

KQUEUE_SRCS = srcs/ServerKqueue.cpp

MAIN_TEST = srcs/MainServerApi.cpp


NAME_PROGRAMM = ircserver

##**********##
### COLORS ###
##**********##
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m
IGREY		= \x1b[40m
IRED		= \033[1;35m
IGREEN		= \x1b[42m
IYELLOW		= \x1b[43m
IBLUE		= \x1b[44m
IPURPLE		= \x1b[45m
ICYAN		= \x1b[46m
IWHITE		= \x1b[47m
END			= \x1b[0m
UNDERLINE	= \x1b[4m
REV			= \x1b[7m

all:
	@echo "$(VIOLET)$(UNDERLINE)Makefile All$(END)$(PURPLE)"


select:
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) $(SRCS) $(SELECT_SRCS) $(MAIN_TEST) -D SELECT -o $(NAME_PROGRAMM)
	
poll:
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) $(SRCS) $(POLL_SRCS) $(MAIN_TEST) -D POLL -o $(NAME_PROGRAMM)

kqueue:
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) $(SRCS) $(KQUEUE_SRCS) $(MAIN_TEST) -D KQUEUE -o $(NAME_PROGRAMM)

epoll:
	$(CXX) $(CPPFLAGS) -I$(INCLUDES) $(SRCS) $(EPOLL_SRCS) $(MAIN_TEST) -D EPOLL -o $(NAME_PROGRAMM)

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(WHITE)  * Make code, *"
	@echo "$(WHITE)   * not war! *"
	@echo "$(RED)    ..10101.."
	@echo "$(YELLOW)  01    1   01"
	@echo "$(VIOLET) 10     0     00"
	@echo "$(GREEN) 11   .010.   11"
	@echo "$(CYAN) 00 .01 1 01. 10"
	@echo "$(BLUE) 010    1   110"
	@echo "$(BLUE)   11011010**$(F_NONE)"
