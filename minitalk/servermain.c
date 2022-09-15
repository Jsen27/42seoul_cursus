/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:48:42 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/15 14:11:37 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void f();
void g();

int	main(void)
{
	int PID;
	struct sigaction act;
	
	
	PID = getpid();
	signal(SIGUSR1, f);
	signal(SIGUSR2, g);
	printf("server PID : %d\n",PID);
	while (1)
	{
		pause();
	}
	return 0;
}

void f()
{
	printf("SIGUSR1 호출 ! \n 서버 종료 !\n");
	exit(0);
}

void g()
{
	printf("SIGUSR2 호출 ! \n 서버 종료 !\n");
	exit(0);
}