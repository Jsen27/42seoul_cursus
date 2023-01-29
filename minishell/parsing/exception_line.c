/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:16:53 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/29 19:57:18 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	set_quote(char c, int quote)
{
	if (c == '\'')
	{
		if (quote == 1)
			return (0);
		else if (quote == 2)
			return (2);
		else
			return (1);
	}
	else if (c == '\"')
	{
		if (quote == 2)
			return (0);
		else if (quote == 1)
			return (1);
		else
			return (2);
	}
	return (quote);
}

static char	*redirect_space(char *str, char *line, char c)
{
	if (c == '>')
	{
		line--;
		if (*line != '>' && *line != ' ')
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, '>');
		line++;
		if (*line != '>' && *line != ' ')
			str = ft_strjoin_char(str, ' ');
	}
	else if (c == '<')
	{
		line--;
		if (*line != '<' && *line != ' ')
			str = ft_strjoin_char(str, ' ');
		line++;
		str = ft_strjoin_char(str, '<');
		line++;
		if (*line != '<' && *line != ' ')
			str = ft_strjoin_char(str, ' ');
	}
	return (str);
}

static char	*get_pipe(char *str, char *line, int *pipe)
{
	if (*pipe == 1)
		return (NULL);
	line--;
	if (*line != ' ')
		str = ft_strjoin_char(str, ' ');
	line++;
	str = ft_strjoin_char(str, '|');
	line++;
	if (*line != ' ')
		str = ft_strjoin_char(str, ' ');
	*pipe = 1;
	return (str);
}

static char	*none_pipe(char *str, char *line, int quote, int *pipe)
{
	if ((*line == ';' || *line == '\\') && quote == 0)
	{
		free(str);
		return (NULL);
	}
	else if (*line == ' ' && quote != 0)
		str = ft_strjoin_char(str, -10);
	else if (check_whitespace(*line) && quote == 0)
	{
		line--;
		if (*line == ' ')
			return (str);
		str = ft_strjoin_char(str, ' ');
	}
	else if ((*line == '>' || *line == '<') && quote == 0)
		str = redirect_space(str, line, *line);
	else
	{
		str = ft_strjoin_char(str, *line);
		*pipe = 0;
	}
	return (str);
}

char	*exception_line(char *line, int quote, int pipe)
{
	char	*str;

	str = NULL;
	if (syntax_redirect(line) || syntax_pipe(line))
		return (NULL);
	while (*line)
	{
		quote = set_quote(*line, quote);
		if (quote == 0 && *line == '|')
			str = get_pipe(str, line, &pipe);
		else
			str = none_pipe(str, line, quote, &pipe);
		if (!str)
			return (NULL);
		line++;
	}
	if (quote)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
