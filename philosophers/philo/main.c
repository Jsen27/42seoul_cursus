/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:39 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/12 18:10:45 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(t_data *data, int error)
{
	if (error == 0)
		printf("Usage : ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else if (error > 0)
	{
		printf("Init error !\n");
		if (error == 2)
			free(data);
	}
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
