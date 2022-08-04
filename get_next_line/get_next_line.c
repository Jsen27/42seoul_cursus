/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:31:03 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/03 16:01:40 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *backup)
{
	int		check;
	char	*temp;

	check = 1;
	while (check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (0);
		else if (check == 0)
			break ;
		buf[check] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = (ft_strjoin(temp, buf));
		if (!backup)
			return (NULL);
		free (temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free (temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
