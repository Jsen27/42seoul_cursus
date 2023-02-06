/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:19 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/30 14:53:19 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	heredoc_to_redirin(t_list *lst, int *fds, int index)
{
	char	*filename;

	filename = get_heredoc_filename(&fds[index]);
	if (!filename)
		system_error("heredoc_to_redirin", "heredoc tmp exceeded maximum", 1);
	free(((t_token *)lst->content)->content);
	((t_token *)lst->content)->content = ft_strdup(filename);
	free(filename);
	((t_token *)lst->content)->type = REDIR_IN;
}

static void	heredoc_readline(char *delim, int fd)
{
	char	*line;

	sig_fork(HEREDOC);
	line = readline("> ");
	while (line)
	{
		if (ft_strncmp(delim, line, ft_strlen(delim)) == 0 && \
				ft_strncmp(delim, line, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	exit(0);
}

static int	fork_redirection(int heredoc_count, int *fds, char **delims)
{
	int		i;
	int		pid;
	int		status;

	i = -1;
	while (++i < heredoc_count)
	{
		pid = fork();
		if (pid < 0)
			system_error("fork_redirection", "fork error", 1);
		else if (pid == 0)
			heredoc_readline(delims[i], fds[i]);
		if (waitpid(pid, &status, 0) < 0)
			system_error("fork_redirection", "waitpid error", 1);
		if (WIFEXITED(status))
			g_status.global_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			g_status.global_exit_status = WTERMSIG(status);
			free_redirection_utils(fds, delims, heredoc_count);
			return (FAIL);
		}
	}
	free_redirection_utils(fds, delims, heredoc_count);
	return (SUCCESS);
}

static int	change_token_and_open(t_commandlist *commandlist, int cmd_count, \
							int heredoc_count, char **delims)
{
	int		*fds;
	int		i;
	int		idx;
	t_list	*lst;

	fds = malloc(sizeof(int) * heredoc_count);
	delims = malloc(sizeof(char *) * heredoc_count);
	if (!fds || !delims)
		system_error("change_token_and_open", "malloc error", 1);
	i = -1;
	idx = 0;
	while (++i < cmd_count)
	{
		lst = commandlist[i].redirection;
		while (lst)
		{
			if (((t_token *)lst->content)->type == REDIR_HEREDOC)
			{
				delims[idx] = ft_strdup(((t_token *)lst->content)->content);
				heredoc_to_redirin(lst, fds, idx++);
			}
			lst = lst->next;
		}
	}
	return (fork_redirection(heredoc_count, fds, delims));
}

int	redirect_heredoc(t_commandlist *commandlist, int cmd_count)
{
	int		i;
	int		count;
	t_list	*lst;
	char	**delims;

	count = 0;
	i = -1;
	delims = NULL;
	while (++i < cmd_count)
	{
		lst = commandlist[i].redirection;
		while (lst)
		{
			if (((t_token *)lst->content)->type == REDIR_HEREDOC)
				count++;
			lst = lst->next;
		}
	}
	if (count == 0)
		return (SUCCESS);
	return (change_token_and_open(commandlist, cmd_count, count, delims));
}
