CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = minishell

LIBFT = libft/libft.a
LIBFT_DIR = libft/

EXEC_FILE = execute.c \
			execute_command.c \
			execute_redir.c \
			execute_utils.c \
			execute_pipe.c \
			execute_builtin.c \
			builtin_cd.c \
			builtin_echo.c \
			builtin_env.c \
			builtin_exit.c \
			builtin_export.c \
			builtin_pwd.c \
			builtin_unset.c \
			envp_utils.c \
			execute_heredoc.c
EXEC_SRCS = $(addprefix execute/, $(EXEC_FILE))
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

PARS_FILE = ascii_change.c \
			convert_dollar.c \
			dollar_utils.c \
			dollar_utils2.c \
			exception_line.c \
			exception_utils.c \
			parsing_redirect.c \
			parsing_utils.c \
			parsing.c
PARS_SRCS = $(addprefix parsing/, $(PARS_FILE))
PARS_OBJS = $(PARS_SRCS:.c=.o)

UTIL_FILE = signal.c \
			error.c \
			free.c
UTIL_SRCS = $(addprefix utils/, $(UTIL_FILE))
UTIL_OBJS = $(UTIL_SRCS:.c=.o)

MAIN_SRCS = minishell.c
MAIN_OBJS = minishell.o

RLFLAGS = -lreadline -lhistory -L$(READ_DIR)
INCLUDES = -I$(READ_HDRS)
READ_DIR = ./readline/lib/
READ_HDRS	= ./readline/include/

OBJS = $(PARS_OBJS) $(EXEC_OBJS) $(UTIL_OBJS) $(MAIN_OBJS)

all : $(NAME)

$(NAME) : rl $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) $(RLFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	rm -rf rlsrc

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -rf readline
	rm -f rl

re : fclean all

rl :
	git clone https://git.savannah.gnu.org/git/readline.git rlsrc
	cd rlsrc && ./configure --prefix="${PWD}/readline"
	$(MAKE) --directory=rlsrc
	$(MAKE) --directory=rlsrc install
	touch rl

.PHONY : clean fclean re