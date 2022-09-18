/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:48:42 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/18 22:23:43 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handler(int signum, siginfo_t *act, void *context)
{
	static int	num = 0;
	static int	count = 0;
	unsigned 	char  a;

	(void)*act;
	(void)*context;
	if (signum == SIGUSR2)
		num += (1 << (7 - count));
	count++;
	if (count == 8 && num == 127)
	{
		ft_printf("\n");
		count = 0;
		num = 0;
	}
	else if (count == 8)
	{
		a = (unsigned char)num;
		write(1, &a, 1);
		count = 0;
		num = 0;
	}
}

int	main(void)
{
	int PID;
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	PID = getpid();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("server PID : %d\n",PID);
	while (1)
	{
		pause();
	}
	return 0;
}

