/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwopa <chanwopa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:40:05 by chanwopa          #+#    #+#             */
/*   Updated: 2023/01/26 20:25:00 by chanwopa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**set_envp(char **envp)
{
	char	**new_envp;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envp[++i])
	{
		if (ft_strchr(envp[i], '='))
			count++;
	}
	new_envp = malloc(sizeof(char *) * (count + 1));
	i = -1;
	count = 0;
	while (envp[++i])
	{
		if (ft_strchr(envp[i], '='))
		{
			new_envp[count] = ft_strdup(envp[i]);
			count++;
		}
	}
	new_envp[count] = NULL;
	return (new_envp);
}

void	change_envp(char *new, t_info *info)
{
	int		i;
	char	*equal_loc;

	equal_loc = ft_strchr(new, '=');
	if (!equal_loc)
		return ;
	i = 0;
	while (info->envp[i])
	{
		if (ft_strncmp(new, info->envp[i], equal_loc - new) == 0)
		{
			free(info->envp[i]);
			info->envp[i] = ft_strdup(new);
		}
		i++;
	}
}

void	add_envp(char *new, t_info *info)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (info->envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		system_error("add_envp", "malloc error", 1);
	i = 0;
	while (info->envp[i])
	{
		new_envp[i] = ft_strdup(info->envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(new);
	i++;
	new_envp[i] = NULL;
	free_strs(info->envp);
	info->envp = new_envp;
}

void	delete_envp(char *del, t_info *info)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * i);
	if (!new_envp)
		system_error("delete_envp", "malloc error", 1);
	i = -1;
	while (info->envp[++i])
	{
		if (ft_strncmp(del, info->envp[i], ft_strlen(del)) == 0 && \
			ft_strncmp(del, info->envp[i], ft_strlen(info->envp[i])) == 0)
			continue ;
		if (ft_strncmp(del, info->envp[i], ft_strlen(del)) == 0 && \
			info->envp[i][ft_strlen(del)] == '=')
			continue ;
		new_envp[j++] = ft_strdup(info->envp[i]);
	}
	new_envp[j] = NULL;
	free_strs(info->envp);
	info->envp = new_envp;
}

/*
	환경변수를 추가, 삭제, 해제, 변경 해주는 함수들
*/