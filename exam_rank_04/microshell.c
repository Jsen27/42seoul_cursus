#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int ft_putstr(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	while (*arg)
		write(2, arg++, 1);
	write(2, "\n", 1);
	return 1;
}

int ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	return (ft_putstr("error: cannot execute ", argv[0]));
}

int main(int argc, char **argv, char **env)
{
	int i;
	int fd[2];
	int tmp_fd;
	(void)argc;

	i = 0;
	tmp_fd = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[i], "cd") == 0)
		{
			if (i != 2)
				ft_putstr("error: cd: bad arguments", NULL);
			else if (chdir(argv[i]) != 0)
				ft_putstr("error: cd: cannot change directory to ", argv[i]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (ft_execute(argv, i, tmp_fd, env))
					return 1;
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(argv, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	while(1)
	;
	close(tmp_fd);
	return 0;
}