/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:07:50 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/30 20:17:46 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	execute_redirect_in(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(filename, "cannot open file or directory", NULL);
		return (FAIL);
	}
	else if (fd != STDIN_FILENO)
	{
		if (dup2(fd, STDIN_FILENO) != STDIN_FILENO)
			system_error("execute_redirect_in", "dup2 error", 1);
		close(fd);
	}
	return (SUCCESS);
}

static int	execute_redirect_out(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_error(filename, "cannot open file or directory", NULL);
		return (FAIL);
	}
	else if (fd != STDOUT_FILENO)
	{
		if (dup2(fd, STDOUT_FILENO) != STDOUT_FILENO)
			system_error("execute_redirect_out", "dup2 error", 1);
		close(fd);
	}
	return (SUCCESS);
}

static int	execute_redirect_append(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		print_error(filename, "cannot open file or directory", NULL);
		return (FAIL);
	}
	else if (fd != STDOUT_FILENO)
	{
		if (dup2(fd, STDOUT_FILENO) != STDOUT_FILENO)
			system_error("execute_redirect_append", "dup2 error", 1);
		close(fd);
	}
	return (SUCCESS);
}

int	redirection(t_list	*redirection)
{
	t_token	*token;
	t_list	*list;

	list = redirection;
	while (list)
	{
		token = (t_token *)list->content;
		if (token->type == REDIR_IN && \
			execute_redirect_in(token->content) == FAIL)
			return (FAIL);
		else if (token->type == REDIR_OUT && \
			execute_redirect_out(token->content) == FAIL)
			return (FAIL);
		else if (token->type == REDIR_APPEND && \
			execute_redirect_append(token->content) == FAIL)
			return (FAIL);
		list = list->next;
	}
	return (SUCCESS);
}
