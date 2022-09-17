/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:48:42 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/17 21:12:48 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void f(int, siginfo_t *, void *);

int	main(void)
{
	int PID;
	struct sigaction act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = f;
	PID = getpid();
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	printf("server PID : %d\n",PID);
	while (1)
	{
		pause();
	}
	return 0;
}

void f(int signum, siginfo_t *act, void *context)
{
	static int	num = 0;
	static int	count = 0;
	static int	q = 1;
	unsigned char  a;

	if(signum == SIGUSR2)
		num += (2 * q);
	q *= 2;
	count++;
	if(count == 8)
	{
		a = (unsigned char)num;
		write(1, &a, 1);
		count = 0;
		num = 0;
		q = 1;
	}
}
