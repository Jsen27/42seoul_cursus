/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:58:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/15 15:26:22 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(int argc, char **argv)
{
	int PID = atoi(argv[1]);

	if (argc != 3){
		printf("매개변수 갯수 오류 !\n");
		return 0;
	}
	if (atoi(argv[2]) == 1)
		kill(PID, SIGUSR1);
	else if (atoi(argv[2]) == 2)
		kill (PID, SIGUSR2);
	else
		printf("1 or 2 를 입력해주세요 ! \n");
	return 0;
}