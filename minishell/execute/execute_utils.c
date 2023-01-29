/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:38:29 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/27 20:28:50 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_commands_count(t_commandlist *commandlist)
{
	int	count;

	count = 0;
	while (commandlist[count].command != NULL || \
			commandlist[count].redirection != NULL)
		count++;
	return (count);
}

char	**list_to_strs(t_list *command)
{
	t_list	*ptr;
	char	**strs;
	int		count;
	int		i;

	count = 0;
	ptr = command;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	i = -1;
	ptr = command;
	while (++i < count)
	{
		strs[i] = ft_strdup(((t_token *)ptr->content)->content);
		ptr = ptr->next;
	}
	strs[i] = NULL;
	return (strs);
}

char	*get_heredoc_filename(int *fd)
{
	char	*filename;
	char	*num;
	int		i;

	i = 0;
	while (++i)
	{
		num = ft_itoa(i);
		filename = ft_strjoin(".heredoc_tmp", num);
		if (num)
			free(num);
		if (!filename)
			system_error("get_heredoc_filename", "malloc error", 1);
		if (access(filename, F_OK) != 0)
		{
			*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (*fd >= 0)
				return (filename);
		}
		free(filename);
	}
	return (NULL);
}

void	set_exit_status_signal(int status)
{
	if (WIFEXITED(status))
		g_status.global_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			g_status.global_exit_status = 130;
		else if (WTERMSIG(status) == 3)
			g_status.global_exit_status = 131;
		else
			g_status.global_exit_status = WTERMSIG(status);
	}
	else
		system_error("execute_command", "exit failure error", 1);
}

int	input_only_spaces(char *input)
{
	while (*input)
	{
		if ((*input >= 9 && *input <= 13) || (*input == ' '))
			input++;
		else
			return (NO);
	}
	return (YES);
}
