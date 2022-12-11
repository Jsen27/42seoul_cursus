/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:39 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/11 21:08:48 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// 홀수 짝수 인원 나눠서 진행

void	*funt()
{

}

void	error_exit(int error)
{
	
}

int	main(int argc, char **argv)
{
	t_data	data;


	args_init(argc, argv, &data);







	int	i;
	
	i = 0;
	while (i < 5) // 5명이라고 가정
	{
		pthread_create(&data.philo[i], NULL, funt, NULL);
		pthread_join(data.philo[i], NULL);
		i++;
	}
	
	pthread_mutex_init(&data.mutex, NULL);
	gettimeofday(&data.first_time, NULL);
	sleep(3);
	gettimeofday(&data.now_time, NULL);
	printf("%ld:%d\n",data.now_time.tv_sec - data.first_time.tv_sec, data.now_time.tv_usec - data.first_time.tv_usec);
	return (0);
}
