/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:40:22 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/28 12:14:07 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	identify_builtin(char *str)
{
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "cd", 2) == 0)
		return (BUILTIN_CD);
	else if (ft_strncmp(str, "echo", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "echo", 4) == 0)
		return (BUILTIN_ECHO);
	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "exit", 4) == 0)
		return (BUILTIN_EXIT);
	else if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "pwd", 3) == 0)
		return (BUILTIN_PWD);
	else if (ft_strncmp(str, "export", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "export", 6) == 0)
		return (BUILTIN_EXPORT);
	else if (ft_strncmp(str, "unset", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "unset", 5) == 0)
		return (BUILTIN_UNSET);
	else if (ft_strncmp(str, "env", ft_strlen(str)) == 0 && \
		ft_strncmp(str, "env", 3) == 0)
		return (BUILTIN_ENV);
	else
		return (NOT_BUILTIN);
}

int	execute_builtin(t_list *command, t_info *info)
{
	t_token		*token;
	t_builtin	bi;

	token = (t_token *)command->content;
	bi = identify_builtin(token->content);
	if (bi == NOT_BUILTIN)
		return (NO);
	else if (bi == BUILTIN_CD)
		builtin_cd(command, info);
	else if (bi == BUILTIN_ECHO)
		builtin_echo(command);
	else if (bi == BUILTIN_PWD)
		builtin_pwd(command);
	else if (bi == BUILTIN_EXPORT)
		builtin_export(command, info);
	else if (bi == BUILTIN_UNSET)
		builtin_unset(command, info);
	else if (bi == BUILTIN_ENV)
		builtin_env(command, info);
	else
		builtin_exit(command);
	return (YES);
}

/*
	built-in function 종류에 따른 함수 호출
*/