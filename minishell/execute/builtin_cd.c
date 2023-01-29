/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:09 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 17:42:17 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	cd_change_envp(char *old_cwd, t_info *info)
{
	char	*str;
	char	*new_pwd;

	str = ft_strjoin("OLDPWD=", old_cwd);
	change_envp(str, info);
	free(str);
	str = getcwd(NULL, 0);
	new_pwd = ft_strjoin("PWD=", str);
	free(str);
	change_envp(new_pwd, info);
	free(new_pwd);
}

void	builtin_cd(t_list *list, t_info *info)
{
	char	*old_cwd;
	char	**command;

	command = list_to_strs(list);
	if (!command)
		system_error("builtin_cd", "malloc error", 1);
	if (!command[1])
		print_error(command[0], "cd without directory invalid", NULL, NO);
	else
	{
		old_cwd = getcwd(NULL, 0);
		if (chdir(command[1]) == -1)
			print_error(command[0], command[1], NULL, YES);
		else
			cd_change_envp(old_cwd, info);
		free(old_cwd);
	}
	free_strs(command);
}

/*
	getcwd 함수를 통해 현재 위치를 받아옴
	chdir 명령을 통해 인자로 받은 디렉토리로 이동을 시도함, 실패하면 -1 반환
	성공했다면 이전에 저장한 old_cwd를 바탕으로 환경변수 OLDPWD를, 
	현재 경로로 환경변수 PWD를 각각 변경해줌
*/
