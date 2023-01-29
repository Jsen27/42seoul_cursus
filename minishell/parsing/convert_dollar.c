/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:27:16 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/29 21:53:17 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_dollar	*just_dollar(t_dollar *lst, char **envp, int i)
{
	if (ft_strlen(lst->str) < 1)
		return (lst);
	else if (lst->str[i] == '$'
		&& (lst->str[i + 1] == ' ' || lst->str[i + 1] == '\0'))
	{
		if (lst->d_temp != NULL)
			lst = convert_envp(lst, envp);
		if (lst->temp == NULL)
			lst->temp = ft_strdup("$");
		else
			lst->temp = ft_strjoin_char(lst->temp, '$');
		if (lst->str[i + 1] == ' ')
		{
			lst->str += 1;
			lst->check = 1;
		}
		else
			lst->check = 2;
		free(lst->d_temp);
		lst->d_temp = NULL;
		lst->dollar = 0;
	}
	return (lst);
}

static t_dollar	*exit_status(t_dollar *lst, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	lst->check = 0;
	if (ft_strlen(lst->str) < 1)
		return (lst);
	else if (lst->str[i] == '$' && lst->str[i + 1] == '?')
	{
		if (lst->d_temp != NULL)
			lst = convert_envp(lst, envp);
		if (lst->temp == NULL)
			lst->temp = ft_itoa(g_status.global_exit_status);
		else
		{
			temp = ft_itoa(g_status.global_exit_status);
			lst = join_and_free(lst, temp);
			free(temp);
		}
		lst = set_dollar_exit(lst);
		return (lst);
	}
	return (lst);
}

static t_dollar	*end_dollar(char **envp, t_dollar *lst)
{
	lst = convert_envp(lst, envp);
	if (*lst->str == '$')
	{	
		lst->d_temp = ft_strjoin_char(lst->d_temp, *lst->str);
	}
	else
	{
		lst->dollar = 0;
		lst->temp = ft_strjoin_char(lst->temp, *lst->str);
	}	
	lst->str++;
	return (lst);
}

static t_dollar	*circuit_str(t_dollar *lst, char **envp)
{
	while (*lst->str)
	{
		if (*lst->str == '$' || lst->dollar == 1)
		{
			lst = exit_status(lst, envp);
			lst = just_dollar(lst, envp, 0);
			if (lst->check == 1)
				continue ;
			else if (lst->check == 2)
				break ;
			if (lst->dollar == 1 && !(ft_isalnum(*lst->str)))
			{
				lst = end_dollar(envp, lst);
				continue ;
			}
			lst->d_temp = ft_strjoin_char(lst->d_temp, *lst->str);
			lst->dollar = 1;
		}
		else if (lst->dollar == 0)
			lst->temp = ft_strjoin_char(lst->temp, *lst->str);
		lst->str++;
	}
	return (lst);
}

char	*convert_dollar(char *str, char **envp)
{
	t_dollar	*lst;
	char		*ret;

	ret = NULL;
	lst = init_dollar(str);
	lst = circuit_str(lst, envp);
	if (lst->dollar == 1)
		lst = convert_envp(lst, envp);
	ret = free_dollar(lst, ret);
	free(lst);
	return (ret);
}
