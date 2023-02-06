/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:02:14 by sehjung           #+#    #+#             */
/*   Updated: 2023/02/01 14:03:16 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_pipe(char *str)
{
	int	cnt;
	int	i;

	cnt = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			cnt++;
		i++;
	}
	return (cnt);
}

int	check_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	char	*ret;
	size_t	s1_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(&s2));
	s1_len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (s1_len + 2));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, &s2, 2);
	free(s1);
	return (ret);
}

void	delete_minus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == -11)
			str[i] = '$';
		else if (str[i] == -20)
			str[i] = '<';
		else if (str[i] == -21)
			str[i] = '>';
		else if (str[i] == -22)
			str[i] = '|';
		i++;
	}
}

t_token	*new_token(char *command, t_type type)
{
	t_token	*new_token;

	if (command == NULL)
		return (NULL);
	new_token = malloc(sizeof(t_token));
	delete_minus(command);
	new_token->content = ft_strdup(command);
	new_token->type = type;
	return (new_token);
}
