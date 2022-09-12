/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:48:42 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/12 21:09:15 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	int PID;

	PID = getpid();
	printf("server PID : %d\n",PID);
	while (1)
	{
		
	}
	return 0;
}