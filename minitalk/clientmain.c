/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:58:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/15 16:44:15 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void convert(int PID, char ch)
{
	int n, c = 0, mok, nmg, i;
    int arr[10];

	n = (int)ch;
    do
    {
        mok = n / 2;
        nmg = n - mok * 2;
        arr[c++] = nmg;
        n = mok;
    } while (mok != 0);

    for(int i = c -1; i >= 0; i--)
	{
		if (arr[i] == 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
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