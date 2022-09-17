/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:58:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/17 20:46:39 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void convert(int PID, unsigned char ch)
{
	int n, i = 0;
    int arr[10];
	int	cnt = 0;

	n = (int)ch;
    while(1)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
		if(n == 0)
			break;
	}

	for(; i < 8; i++)
		arr[i] = 0;
	
	//test
	for(int i = 7; i >= 0; i--)
		printf("%d",arr[i]);

    for(int i = 7; i >= 0; i--)
	{
		if (arr[i] == 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(1000);
	}

}


int	main(int argc, char **argv)
{
	int PID = atoi(argv[1]);

	if (argc != 3){
		printf("매개변수 갯수 오류 !\n");
		return 0;
	}
	convert(PID, argv[2][0]);
	return 0;
}