/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:48:36 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/11 09:38:27 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_save_b(char **save_b, int index)
{
	char	*tmp_str;
	char	*ret_str;

	tmp_str = *save_b;
	ret_str = gnl_substr(*save_b, 0, index + 1);
	*save_b = gnl_substr(*save_b, index + 1, gnl_strlen(*save_b) - index - 1);
	free(tmp_str);
	return (ret_str);
}

char	*read_nothing_in_buf(char *buf, char **save_b, int check)
{
	char	*ret_str;

	if (check == -1)
	{
		free(buf);
		free(*save_b);
		*save_b = 0;
		return (NULL);
	}
	free(buf);
	if (**save_b != '\0')
	{
		ret_str = gnl_strjoin("", *save_b);
		free(*save_b);
		*save_b = gnl_strjoin("", "");
		return (ret_str);
	}
	free(*save_b);
	*save_b = 0;
	return (NULL);
}

char	*read_newline_line(char *buf, char **save_b, int check, size_t index)
{
	char	*tmp_str;
	char	*ret_str;

	tmp_str = gnl_substr(buf, 0, index + 1);
	ret_str = gnl_strjoin(*save_b, tmp_str);
	free(tmp_str);
	tmp_str = *save_b;
	*save_b = gnl_substr(buf, index + 1, check - index - 1);
	free(tmp_str);
	free(buf);
	return (ret_str);
}

int	have_newline_in_buf(char *buf, char **save_b, char **ret_str, int fd)
{
	size_t	index;
	char	*tmp_str;
	int		length;

	index = -1;
	while (++ index < ((size_t)BUFFER_SIZE + 1))
		*(buf + index) = '\0';
	length = read(fd, buf, (size_t)BUFFER_SIZE);
	if (length == 0 || length == -1)
	{
		*ret_str = read_nothing_in_buf(buf, save_b, length);
		return (1);
	}
	index = 0;
	while (*(buf + index) != '\n' && index < (size_t)length)
		index ++;
	if (index != (size_t)length)
	{
		*ret_str = read_newline_line(buf, save_b, length, index);
		return (1);
	}
	tmp_str = *save_b;
	*save_b = gnl_strjoin(*save_b, buf);
	free(tmp_str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save_b = 0;
	char		*buf;
	char		*ret_str;
	size_t		index;

	if (save_b == 0)
	{
		save_b = (char *)malloc(1);
		*save_b = '\0';
	}
	index = 0;
	while (*(save_b + index) != '\n' && *(save_b + index))
		index ++;
	if (index != gnl_strlen(save_b))
		return (read_save_b(&save_b, index));
	buf = malloc(((size_t)BUFFER_SIZE + 1));
	while (1)
	{
		if (have_newline_in_buf(buf, &save_b, &ret_str, fd))
			return (ret_str);
	}
}
