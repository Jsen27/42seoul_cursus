/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:57:13 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/28 13:04:53 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	wait_piped_pids(pid_t *pids, int cmd_count)
{
	int	status;
	int	i;

	i = -1;
	while (++i < cmd_count)
	{
		if (i == cmd_count - 1)
		{
			if (waitpid(pids[i], &status, 0) < 0)
				system_error("wait_piped_pids", "waitpid error", 1);
		}
		else
		{
			if (waitpid(pids[i], NULL, 0) < 0)
				system_error("wait_piped_pids", "waitpid error", 1);
		}
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else
		system_error("wait_piped_pids", "exit failure error", 1);
	return (EXIT_FAILURE);
}

static void	init_pipes(int cmd_count, pid_t **pids, int ***pipes)
{
	int	i;

	(*pids) = malloc(sizeof(pid_t) * cmd_count);
	(*pipes) = malloc(sizeof(int *) * (cmd_count - 1));
	if (!(*pids) || !(*pipes))
		system_error("init_pipes", "malloc error", 1);
	i = -1;
	while (++i < cmd_count - 1)
	{
		(*pipes)[i] = malloc(sizeof(int) * 2);
		if (!((*pipes)[i]))
			system_error("init_pipes", "malloc error", 1);
	}
	ft_memset(*pids, 255, sizeof(pid_t) * cmd_count);
}

/*	
	pipes : (cmd_count - 1) 크기의 int[2] array
	cmd_count == 2 이라고 가정했을 때, pids는 
	0번째 프로세스는 pids[0][1]을 STDOUT으로 설정
	1번째 프로세스는 pids[0][0]을 STDIN으로 설정
*/
static void	set_pipeline(int child_index, int cmd_count, int ***pipes)
{
	int	i;

	i = -1;
	while (++i < cmd_count - 1)
	{
		if (i == child_index - 1)
		{
			if ((*pipes)[i][0] != STDIN_FILENO)
				if (dup2((*pipes)[i][0], STDIN_FILENO) != STDIN_FILENO)
					system_error("set_pipeline", "dup2 error", 1);
			close((*pipes)[i][1]);
		}
		else if (i == child_index)
		{
			if ((*pipes)[i][1] != STDOUT_FILENO)
				if (dup2((*pipes)[i][1], STDOUT_FILENO) != STDOUT_FILENO)
					system_error("set_pipeline", "dup2 error", 1);
			close((*pipes)[i][0]);
		}
		else
		{
			close((*pipes)[i][0]);
			close((*pipes)[i][1]);
		}
	}
}

static void	build_pipeline(int cmd_count, pid_t **pids, int ***pipes)
{
	int	i;

	i = -1;
	while (++i < cmd_count - 1)
	{
		if (pipe((*pipes)[i]) < 0)
			system_error("build_pipeline", "pipe error", 1);
	}
	i = -1;
	while (++i < cmd_count)
	{
		(*pids)[i] = fork();
		if ((*pids)[i] < 0)
			system_error("build_pipeline", "fork error", 1);
		else if ((*pids)[i] == 0)
		{
			set_pipeline(i, cmd_count, pipes);
			return ;
		}
	}
}

void	execute_pipe(t_commandlist *commandlist, t_info *info, int cmd_count)
{
	pid_t	*pids;
	int		**pipes;
	int		i;

	init_pipes(cmd_count, &pids, &pipes);
	build_pipeline(cmd_count, &pids, &pipes);
	i = -1;
	while (++i < cmd_count)
	{
		if (pids[i] == 0)
		{
			info->issubshell = YES;
			execute_subshell(commandlist[i], info);
		}
	}
	i = -1;
	while (++i < cmd_count - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
	}
	free(pipes);
	g_status.global_exit_status = wait_piped_pids(pids, cmd_count);
	free(pids);
}
