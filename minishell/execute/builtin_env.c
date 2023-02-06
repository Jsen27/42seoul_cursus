/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:52:55 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/30 20:15:19 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_list *list, t_info *info)
{
	char	**command;
	int		i;

	command = list_to_strs(list);
	if (!command)
		system_error("builtin_env", "malloc error", 1);
	if (command[1])
		print_error(command[0], command[1], "too many argument");
	else
	{
		i = -1;
		while (info->envp[++i])
		{
			if (ft_strchr(info->envp[i], '='))
			{
				printf("%s\n", info->envp[i]);
			}
		}
	}
	free_strs(command);
}
