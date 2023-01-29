/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:41:26 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/29 19:58:23 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*free_dollar(t_dollar *lst, char *ret)
{
	if (lst->temp)
	{
		ret = ft_strdup(lst->temp);
		free(lst->temp);
	}
	if (lst->d_temp)
		free(lst->d_temp);
	return (ret);
}

t_dollar	*convert_envp(t_dollar *lst, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	lst->d_temp++;
	while (envp[i])
	{
		if (ft_strncmp(lst->d_temp, envp[i], ft_strlen(lst->d_temp)) == 0
			&& envp[i][ft_strlen(lst->d_temp)] == '=')
		{
			temp = envp_to_str(lst->d_temp, envp, i);
			if (!lst->temp)
				lst->temp = ft_strdup(temp);
			else
				lst = join_and_free(lst, temp);
			free(temp);
			break ;
		}
		i++;
	}
	lst->d_temp--;
	free(lst->d_temp);
	lst->d_temp = NULL;
	return (lst);
}

t_dollar	*init_dollar(char *str)
{
	t_dollar	*lst;

	lst = malloc(sizeof(t_dollar));
	if (!lst)
		return (NULL);
	lst->dollar = 0;
	lst->check = 0;
	lst->str = str;
	lst->temp = NULL;
	lst->d_temp = NULL;
	return (lst);
}

char	*envp_to_str(char *str, char **envp, int i)
{
	int		mystrlen;
	int		envlen;
	char	*temp;

	mystrlen = ft_strlen(str);
	envlen = ft_strlen(envp[i]) - mystrlen;
	temp = ft_substr(envp[i], mystrlen + 1, envlen - 1);
	return (temp);
}

int	find_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
