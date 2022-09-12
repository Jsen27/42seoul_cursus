/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:58:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/12 21:11:41 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int PID;
	char *str;

	scanf("%d, %s", &PID, str);
	kill(PID, 9);
	return 0;
}