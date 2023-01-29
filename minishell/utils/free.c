/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:18:23 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/29 18:29:59 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_strs(char **strs)
{
	int	i;

	if (strs)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	free_lists(t_list *list)
{
	t_list	*ptr;
	t_list	*remover;

	ptr = list;
	while (ptr)
	{
		remover = ptr;
		ptr = ptr->next;
		if (remover->content)
		{
			free(((t_token *)remover->content)->content);
			free(remover->content);
		}
		if (remover)
			free(remover);
	}
}

void	free_commands(t_commandlist *commandlist)
{
	int	i;

	if (!commandlist)
		return ;
	i = 0;
	while (commandlist[i].command || commandlist[i].redirection)
	{
		if (commandlist[i].command)
			free_lists(commandlist[i].command);
		if (commandlist[i].redirection)
			free_lists(commandlist[i].redirection);
		i++;
	}
	free(commandlist);
}

void	free_redirection_utils(int *fds, char **delims, int heredoc_count)
{
	int	i;

	i = 0;
	while (i < heredoc_count)
	{
		close(fds[i]);
		if (delims[i])
			free(delims[i]);
		i++;
	}
	free(fds);
	free(delims);
}
