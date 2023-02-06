/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:46:51 by sehjung           #+#    #+#             */
/*   Updated: 2023/02/01 14:10:59 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	init_list(t_commandlist *lst, int cnt)
{
	int	i;

	i = 0;
	if (i < cnt)
	{
		lst[i].command = NULL;
		lst[i].redirection = NULL;
		i++;
	}
}

static void	free_parsing_str(char *str, char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
		free(split_str[i++]);
	free(split_str);
	free(str);
}

char	*free_temp(char *temp)
{
	free(temp);
	return (NULL);
}

t_commandlist	*lst_parse(char **str, t_commandlist *lst, char **envp, int j)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = -1;
	while (str[++i])
	{
		if (str[i][0] == '>')
			ft_lstadd_back(&lst[j].redirection, redirect_out(str, i++, envp));
		else if (str[i][0] == '<')
			ft_lstadd_back(&lst[j].redirection, redirect_in(str, i++, envp));
		else if (str[i][0] == '|')
			j++;
		else if (find_dollar(str[i]))
		{
			temp = convert_dollar(str[i], envp);
			ft_lstadd_back(&lst[j].command,
				ft_lstnew(new_token(temp, COMMAND)));
			temp = free_temp(temp);
		}
		else
			ft_lstadd_back(&lst[j].command,
				ft_lstnew(new_token(str[i], COMMAND)));
	}
	return (lst);
}

t_commandlist	*parsing(char *line, char **envp)
{
	char			*str;
	char			**split_str;
	t_commandlist	*lst;

	if (line[0] == '\0')
		return (NULL);
	str = exception_line(line, 0, 1);
	if (!str)
		return (NULL);
	split_str = ft_split(str, ' ');
	ascii_change(split_str);
	lst = ft_calloc((count_pipe(str) + 1), sizeof(t_commandlist));
	if (!lst)
		return (NULL);
	init_list(lst, count_pipe(str) + 1);
	lst_parse(split_str, lst, envp, 0);
	free_parsing_str(str, split_str);
	return (lst);
}
