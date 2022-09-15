/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:48:42 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/15 15:58:20 by sehjung          ###   ########.fr       */
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
	if (signum == SIGUSR1)
		printf("SIGUSR1 호출 !\n");
	else if (signum == SIGUSR2)
		printf("SIGUSR2 호출 !\n");
}
