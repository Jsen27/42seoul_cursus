/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:31:03 by sehjung           #+#    #+#             */
/*   Updated: 2022/07/18 15:53:51 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5 // 삭제해야함 (input)

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
		temp[check] = '\0';
		if(!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = (ft_strjoin(temp, buf));
		if (!backup)
			return (NULL);
		free (temp);
		temp = NULL;
		if (ft_strchr(buf,'\n'));
			break;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup);
}
