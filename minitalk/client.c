/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:58:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/20 08:05:36 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	convert(int pid, char ch)
{
	int	n;
	int	i;
	int	arr[10];

	i = 0;
	n = (int)ch;
	while (1)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
		if (n == 0)
			break ;
	}
	while (i < 8)
		arr[i++] = 0;
	i--;
	while (i >= 0)
	{
		if (arr[i--] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
	}
}

static void	send_str(int pid, char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		convert(pid, str[i++]);
		usleep(300);
	}
	convert(pid, 127);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("매개변수 갯수 오류 !\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
