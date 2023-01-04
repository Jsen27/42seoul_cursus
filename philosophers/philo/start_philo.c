/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:23:01 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/04 21:06:31 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philosophers(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_m);
	pthread_mutex_destroy(&data->monitor);
	free(data->forks);
	i = 0;
	while (i < data->cnt)
		pthread_mutex_destroy(&philo[i++].finish_check);
	free(philo);
}

void	*just_one_philo(void *arg)
{
	t_philo	*philo;
	int		check;

	philo = arg;
	check = 0;
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	while (!check)
	{
		pthread_mutex_lock(&philo->data->monitor);
		check = philo->data->finish_check;
		pthread_mutex_unlock(&philo->data->monitor);
		usleep(100);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	int	must_eat;

	pthread_mutex_lock(&philo->data->monitor);
	must_eat = philo->data->must_eat;
	pthread_mutex_unlock(&philo->data->monitor);
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	print_stats(philo->data, "has taken a fork", philo->num + 1);
	print_stats(philo->data, "is eating", philo->num + 1);
	pthread_mutex_lock(&philo->finish_check);
	philo->last_eat = now_time(philo->data);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->finish_check);
	clear_sleep(philo->data->eat_time, philo->data);
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
	if (must_eat != 0 && must_eat == philo->eat_cnt)
		return (1);
	print_stats(philo->data, "is sleeping", philo->num + 1);
	clear_sleep(philo->data->sleep_time, philo->data);
	return (0);
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;
	int		check;

	philo = arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->monitor);
		check = philo->data->finish_check;
		pthread_mutex_unlock(&philo->data->monitor);
		if (check)
			break ;
		if (eating(philo))
		{	
			pthread_mutex_lock(&philo->finish_check);
			philo->finish = 1;
			pthread_mutex_unlock(&philo->finish_check);
			break ;
		}
		print_stats(philo->data, "is thinking", philo->num + 1);
	}
	return (0);
}

int	philosophers(t_data *data, t_philo *philo)
{
	int	i;
	int	n;

	i = -1;
	n = data->cnt;
	if (n == 1)
	{
		if (pthread_create(&philo[0].pid, NULL, just_one_philo, &(philo[0])))
			return (1);
	}
	else
	{
		while (++i < n)
		{
			if (pthread_create(&philo[i].pid, NULL, thread_philo, &(philo[i])))
				return (1);
			if (i % 2)
				usleep(10);
		}
	}
	check_finish(data, philo);
	i = 0;
	while (i < n)
		pthread_join(philo[i++].pid, NULL);
	return (0);
}
