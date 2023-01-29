/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:11 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/27 20:29:04 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_env_path(char **env)
{
	char	*path;

	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (*env == NULL)
		path = NULL;
	else
	{
		path = ft_strchr(*env, '=') + 1;
		if (*path == '\0')
			path = NULL;
	}
	return (path);
}

static char	*merge_command_path(char *command, char *path, size_t path_len)
{
	size_t	command_len;
	char	*cmd;

	command_len = ft_strlen(command);
	cmd = malloc(sizeof(char) * (command_len + path_len + 2));
	if (!cmd)
		system_error("merge_command_path", "malloc error", 1);
	ft_memcpy(cmd, path, path_len);
	cmd[path_len] = '/';
	ft_memcpy(cmd + path_len + 1, command, command_len);
	cmd[path_len + command_len + 1] = '\0';
	return (cmd);
}

static char	*get_cmd_from_path(char *command, char *path)
{
	size_t	path_len;
	char	*ptr;
	char	*cmd;

	if (!path || !command)
		return (NULL);
	while (*path)
	{
		ptr = path;
		while (*ptr && *ptr != ':')
			ptr++;
		if (ptr == path)
		{
			path_len = 1;
			path = ".";
		}
		else
			path_len = ptr - path;
		cmd = merge_command_path(command, path, path_len);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		path = ptr + 1;
	}
	return (NULL);
}

void	execute_command(t_list *command, t_info *info)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		system_error("execute_command", "fork error", 1);
	else if (pid == 0)
	{
		info->issubshell = YES;
		execute_command_subshell(command, info->envp);
	}
	safe_signal(SIGINT, SIG_IGN);
	if (waitpid(pid, &status, 0) < 0)
		system_error("execute_command", "waitpid error", 1);
	safe_signal(SIGINT, sig_process);
	set_exit_status_signal(status);
}

void	execute_command_subshell(t_list *command_list, char **envp)
{
	char	**argv;
	char	**env;
	char	*path;
	char	*cmd;

	argv = list_to_strs(command_list);
	if (!argv)
		system_error("execute_command_subshell", "malloc error", 1);
	sig_fork(SUBSHELL);
	env = envp;
	if (ft_strchr(argv[0], '/'))
		cmd = argv[0];
	else
	{
		path = get_env_path(env);
		cmd = get_cmd_from_path(argv[0], path);
		if (!path || !cmd)
			system_error(argv[0], ": command not found", 127);
	}
	if (chdir(cmd) == -1 && access(cmd, F_OK) != 0)
		system_error(argv[0], ": No such file or directory", 127);
	if (execve(cmd, argv, envp) < 0)
		system_error(argv[0], ": cannot execute command", 127);
	free_strs(argv);
	free(cmd);
}
