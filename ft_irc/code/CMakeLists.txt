cmake_minimum_required(VERSION 3.21)

project(ircserver)

include_directories(includes)
#dd_definitions(-DKQUEUE)
add_compile_options(-DKQUEUE)
#add_compile_options(-DPOLL)
#add_compile_options(-DEPOLL)

set(HDRS
		includes/Channel.hpp
		includes/ClientIrc.hpp includes/Color.hpp includes/IrcServer.hpp
		includes/IrcServerProtocol.hpp includes/ServerApi.hpp
		includes/ServerEpoll.hpp includes/ServerKqueue.hpp includes/ServerPoll.hpp
		includes/ServerSelect.hpp includes/utility.hpp)

set(SRCS
		srcs/ServerApi.cpp srcs/IrcServer.cpp
		srcs/utility.cpp srcs/IrcServerCommands.cpp
		srcs/Channel.cpp srcs/ServerSelect.cpp
        srcs/ServerEpoll.cpp
        srcs/ServerKqueue.cpp
        srcs/ServerPoll.cpp
        )

add_executable(ircserver srcs/MainServerApi.cpp ${SRCS} ${HDRS})