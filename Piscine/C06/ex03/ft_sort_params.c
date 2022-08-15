/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:56:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/31 00:35:31 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (1)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
		{
			if (c1 > c2)
				return (1);
			else
				return (0);
		}
		if (!c1)
		{
			break ;
		}
		i++;
	}
	return (0);
}

void	ft_printstr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_printstr(argc, argv);
	return (0);
}
