/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:12:35 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/27 18:07:31 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list	*init_append(char **str, char **envp, int i, int d)
{
	t_list	*temp;

	temp = NULL;
	if (d)
		temp = ft_lstnew(new_token(convert_dollar(str[++i], envp),
					REDIR_APPEND));
	else
		temp = ft_lstnew(new_token(str[++i], REDIR_APPEND));
	return (temp);
}

t_list	*redirect_in(char **str, int i, char **envp)
{
	t_list	*temp;
	int		d;

	temp = NULL;
	if (str[i + 1] == NULL)
		return (NULL);
	d = find_dollar(str[i + 1]);
	if (str[i][0] == '<')
	{
		if (str[i][1] == '<' && ft_strlen(str[i]) == 2)
				temp = ft_lstnew(new_token(str[++i], REDIR_HEREDOC));
		else if (str[i][1] == '\0')
		{
			if (d)
				temp = ft_lstnew(new_token(convert_dollar(str[++i], envp),
							REDIR_IN));
			else
				temp = ft_lstnew(new_token(str[++i], REDIR_IN));
		}
		else
			return (NULL);
	}
	return (temp);
}

t_list	*redirect_out(char **str, int i, char **envp)
{
	t_list	*temp;
	int		d;

	temp = NULL;
	if (str[i + 1] == NULL)
		return (NULL);
	d = find_dollar(str[i + 1]);
	if (str[i][0] == '>')
	{
		if (str[i][1] == '>' && ft_strlen(str[i]) == 2)
			temp = init_append(str, envp, i, d);
		else if (str[i][1] == '\0')
		{
			if (d)
				temp = ft_lstnew(new_token(convert_dollar(str[++i], envp),
							REDIR_OUT));
			else
				temp = ft_lstnew(new_token(str[++i], REDIR_OUT));
		}
		else
			return (NULL);
	}
	return (temp);
}
