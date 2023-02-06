/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:29:21 by chanwopa          #+#    #+#             */
/*   Updated: 2023/02/01 21:54:12 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	bash 환경에서 heredoc은 최대 16개, pipe 개수 등에 상관없이 전체 heredoc이 16개 넘으면
	바로 exit로 종료한다
*/
static int	check_heredoc_count(t_commandlist *commandlist)
{
	int		h_count;
	int		i;
	t_list	*ptr;
	t_token	*token;

	h_count = 0;
	i = 0;
	while (commandlist[i].command != NULL || commandlist[i].redirection != NULL)
	{
		ptr = commandlist[i].redirection;
		while (ptr)
		{
			token = (t_token *)ptr->content;
			if (token->type == REDIR_HEREDOC)
				h_count++;
			ptr = ptr->next;
		}
		i++;
	}
	return (h_count);
}

/*
	parsing 부분에서 잘못된 input은 전부 걸러준다고 생각함.
	이는 정상적으로 구성된 리스트로 구성됬고, 끝에 두 포인터가 NULL이며,
	적어도 하나 이상의 command가 들어있다는 것을 보장함
	command 개수에 따라 바로 execute_subshell 하거나, (단일 command)
	pipelining 후 각 command당 fork 후 execute_subshell 하게됨
*/
int	execute(t_commandlist *commandlist, t_info *info)
{
	int	command_count;
	int	result;

	g_status.global_exit_status = 0;
	command_count = get_commands_count(commandlist);
	if (check_heredoc_count(commandlist) > 16)
		system_error("maximum here-document count exceeded", NULL, 2);
	if (command_count == 0)
		return (0);
	result = redirect_heredoc(commandlist, command_count);
	if (result == FAIL)
		return (0);
	if (command_count == 1)
		execute_subshell(commandlist[0], info);
	else
		execute_pipe(commandlist, info, command_count);
	return (0);
}

/*
	redirection이 없을경우 redirection = NULL일것
	있을경우 redirection을 수행
	built-in 확인, 아니면 execute_command 로 command를 실행
	현재 프로세스가 subshell일경우 exit로 종료
	메인 프로세스일 경우 STDIN, STDOUT을 다시 원래대로 되돌려준다.
*/
int	execute_subshell(t_commandlist commandlist, t_info *info)
{
	int	result;

	result = SUCCESS;
	if (commandlist.redirection)
		result = redirection(commandlist.redirection);
	if (commandlist.command && result == SUCCESS)
	{
		if (execute_builtin(commandlist.command, info) == NO)
			execute_command(commandlist.command, info);
	}
	if (info->issubshell == YES)
	{
		exit(g_status.global_exit_status);
	}
	if (commandlist.redirection)
		reset_redirection(info);
	return (0);
}

int	reset_redirection(t_info *info)
{
	if (info->fd[0] != STDIN_FILENO)
	{
		if (dup2(info->fd[0], STDIN_FILENO) != STDIN_FILENO)
			system_error("reset_redirection", "dup2 error", 1);
	}
	if (info->fd[1] != STDOUT_FILENO)
	{
		if (dup2(info->fd[1], STDOUT_FILENO) != STDOUT_FILENO)
			system_error("reset_redirection", "dup2 error", 1);
	}
	if (info->fd[2] != STDERR_FILENO)
	{
		if (dup2(info->fd[2], STDERR_FILENO) != STDERR_FILENO)
			system_error("reset_redirection", "dup2 error", 1);
	}
	return (0);
}
