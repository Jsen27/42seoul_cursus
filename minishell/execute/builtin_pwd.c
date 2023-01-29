/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:06:26 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 16:50:24 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(t_list *list)
{
	char	**command;
	char	*pwd;

	command = list_to_strs(list);
	if (!command)
		system_error("builtin_pwd", "malloc error", 1);
	if (command[1])
	{
		print_error(command[0], command[1], "too many arguments", NO);
		free_strs(command);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		print_error(command[0], command[1], "too many arguments", NO);
		free_strs(command);
		return ;
	}
	printf("%s\n", pwd);
	free(pwd);
	free_strs(command);
}

/*
	subject에서 pwd는 인자와 옵션 없는 기능만 구현하면 된다고 작성됨
	따라서, command[1] 이 NULL 이 아니면 두번째 인자가 들어온 것이므로 예외처리
	이후 getcwd로 현재 위치를 받아와 출력해준다.
*/