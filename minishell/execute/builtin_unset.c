/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:52:49 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 19:19:43 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_unset(t_list *list, t_info *info)
{
	char	**command;
	int		i;

	command = list_to_strs(list);
	if (!command)
		system_error("builtin_unset", "malloc error", 1);
	if (command[1])
	{
		i = 1;
		while (command[i])
		{
			if (!ft_strchr(command[i], '\'') && !ft_strchr(command[i], '=') && \
				!ft_strchr(command[i], '\"') && !ft_strchr(command[i], '$'))
				delete_envp(command[i], info);
			else
			{
				errno = 22;
				print_error(command[0], command[i], \
							"not a valid identifier", YES);
			}
			i++;
		}
	}
	free_strs(command);
}

/*
	unset은 환경 변수를 제거하는 built-in function, 여러 인자를 동시에 받을 수 있음
	따라서, while문을 돌면서 각 인자를 delete_envp 함수를 통해 제거
	이때, 원래는 환경변수 이름이 들어오는 인자에 모든 메타문자가 포함될 수 없는데
	subject에서 메타문자는 명시된 것 의외에 따로 해석할 필요 없다고 했으므로, 
	= ' " $ 가 들어오면 예외처리
*/

/* 수정사항 : = 기준으로 단어 찾고 제거하는게 아니라, 쉘 변수도 제거할 수 있어야 함 */