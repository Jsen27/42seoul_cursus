/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:10:22 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/23 20:34:29 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	print_stats(philo->data, "is eating", philo->num + 1);
	usleep(philo->data->eat_time * 1000);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
	if (philo->data->must_eat != 0 && philo->data->must_eat <= philo->eat_cnt)
		return ;
	print_stats(philo->data, "is sleeping", philo->num + 1);
	usleep(philo->data->sleep_time * 1000);
}

void	*funt(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->num % 2)
		usleep(1000);
	while (1)
	{
		eating(philo);
		if (philo->eat_cnt >= philo->data->must_eat)
			break ;
		print_stats(philo->data, "is thinking", philo->num + 1);
	}
	return (0);
}

void	start_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		pthread_create(&philo[i].pid, NULL, funt, &(philo[i]));
		i++;
	}
	i = 0;
	while (i < data->cnt)
	{
		pthread_join(philo[i].pid, NULL);
		i++;
	}
	i = 0;
	while (i < data->cnt)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}