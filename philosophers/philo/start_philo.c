/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:23:01 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/24 20:49:32 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->cnt)
		{
			if (now_time() - philo[i].last_eat > data->die_time)
			{
				print_stats(philo->data, "died", i + 1);
				exit(1);
			}
			i++;
		}
		i = -1;
		while (i < data->cnt)
		{
			if (philo[++i].finish == 0)
				break ;
			else if (i == data->cnt - 1)
				return ;
		}
	}
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	print_stats(philo->data, "is eating", philo->num + 1);
	philo->last_eat = now_time();
	clear_sleep(philo->data->eat_time);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
	if (philo->data->must_eat != 0 && philo->data->must_eat == philo->eat_cnt)
		return (1);
	print_stats(philo->data, "is sleeping", philo->num + 1);
	clear_sleep(philo->data->sleep_time);
	return (0);
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->num % 2)
		usleep(100);
	while (1)
	{
		if (eating(philo))
		{
			philo->finish = 1;
			return (0);
		}
		print_stats(philo->data, "is thinking", philo->num + 1);
	}
}

void	philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		pthread_create(&philo[i].pid, NULL, thread_philo, &(philo[i]));
		i++;
	}
	check_die(data, philo);
	i = 0;
	while (i < data->cnt)
		pthread_join(philo[i++].pid, NULL);
	i = 0;
	while (i < data->cnt)
		pthread_mutex_destroy(&data->forks[i++]);
}
