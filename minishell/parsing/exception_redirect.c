/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:50:03 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/30 20:54:58 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*space_out(char *str, char *line)
{
	line--;
	if (*line != '>' && *line != ' ')
		str = ft_strjoin_char(str, ' ');
	line++;
	str = ft_strjoin_char(str, '>');
	line++;
	if (*line != '>' && *line != ' ')
		str = ft_strjoin_char(str, ' ');
	if (*line == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static char	*space_in(char *str, char *line)
{
	line--;
	if (*line != '<' && *line != ' ')
		str = ft_strjoin_char(str, ' ');
	line++;
	str = ft_strjoin_char(str, '<');
	line++;
	if (*line != '<' && *line != ' ')
		str = ft_strjoin_char(str, ' ');
	if (*line == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*redirect_space(char *str, char *line, char c)
{
	if (c == '>')
		str = space_out(str, line);
	else if (c == '<')
		str = space_in(str, line);
	return (str);
}
