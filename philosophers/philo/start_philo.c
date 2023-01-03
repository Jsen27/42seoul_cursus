/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:23:01 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/03 18:37:47 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	just_one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	while (!(philo->data->finish_check))
	{
		usleep(100);
	}
	return (0);
}

void	check_die(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->finish_check))
	{
		i = -1;
		while (++i < data->cnt)
		{
			if (now_time() - philo[i].last_eat > data->die_time)
			{
				print_stats(philo->data, "died", i + 1);
				data->finish_check = 1;
				return ;
			}
		}
		i = -1;
		while (++i < data->cnt)
		{
			if (philo[i].finish == 0)
				break ;
			else if (i == data->cnt - 1)
				data->finish_check = 1;
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
	clear_sleep(philo->data->eat_time, philo->data);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
	if (philo->data->must_eat != 0 && philo->data->must_eat == philo->eat_cnt)
		return (1);
	print_stats(philo->data, "is sleeping", philo->num + 1);
	clear_sleep(philo->data->sleep_time, philo->data);
	return (0);
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->num % 2)
		usleep(100);
	if (philo->data->cnt == 1)
	{
		just_one_philo(philo);
		return (0);
	}
	while (philo->data->finish_check == 0)
	{
		if (eating(philo))
		{
			philo->finish = 1;
			break ;
		}
		print_stats(philo->data, "is thinking", philo->num + 1);
	}
	return (0);
}

int	philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		if (pthread_create(&philo[i].pid, NULL, thread_philo, &(philo[i])))
			return (1);
		i++;
	}
	check_die(data, philo);
	i = 0;
	while (i < data->cnt)
		pthread_join(philo[i++].pid, NULL);
	i = 0;
	while (i < data->cnt)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	free(philo);
	return (0);
}
