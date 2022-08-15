/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:39:08 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/08 14:39:32 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		len;
	int		file;
	char	c;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
			write(2, "Cannot read file.\n", 18);
		else
		{
			len = read(file, &c, 1);
			while (len)
			{
				write(1, &c, 1);
				len = read(file, &c, 1);
			}
			close(file);
		}
	}
	return (0);
}