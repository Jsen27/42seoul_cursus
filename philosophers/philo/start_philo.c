/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:10:22 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/15 18:24:01 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	struct timeval	temp;
	printf("%lfms %d is eating\n", print_time(&philo->data), philo->num);
	while (1)
	{
		gettimeofday(&temp, NULL);
		if (philo->data->now_time.tv_usec - temp.tv_usec >= philo->data->eat_time)
			break;
		usleep(1000);
	}
	printf("%lfms %d is sleeping\n", print_time(&philo->data), philo->num);
}

void	*funt(t_philo *philo)
{
	while (1)
	{
		if (!pthread_mutex_lock(&philo->data->forks[philo->left]))
			printf("%lfms %d has taken a fork\n", print_time(philo->data), philo->num);
		if (!pthread_mutex_lock(&philo->data->forks[philo->right]))
			printf("%lfms %d has taken a fork\n", print_time(philo->data), philo->num);
		eating(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
		usleep(philo->data->sleep_time);
	}
}

void	start_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		pthread_create(&philo[i].pid, NULL, funt, &philo[i]);
		sleep(1);
		i++;
	}
	i = 0;
	while (i < data->cnt)
		pthread_join(philo[i++].pid, NULL);
}
