/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:35:41 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/05 17:04:30 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die(t_data *data, t_philo *philo)
{
	int	last_eat;
	int	die_time;
	int	i;

	i = 0;
	pthread_mutex_lock(&data->monitor);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->monitor);
	pthread_mutex_lock(&philo->finish_check);
	last_eat = philo->last_eat;
	pthread_mutex_unlock(&philo->finish_check);
	if (now_time(data) - last_eat > die_time)
	{
		print_stats(philo->data, "died", i + 1);
		pthread_mutex_lock(&data->die_m);
		data->die_check = 1;
		pthread_mutex_unlock(&data->die_m);
		pthread_mutex_lock(&data->monitor);
		data->finish_check = 1;
		pthread_mutex_unlock(&data->monitor);
		return (1);
	}
	return (0);
}

static int	check_must_eat(t_data *data, t_philo *philo)
{
	int	i;
	int	n;

	i = 0;
	pthread_mutex_lock(&data->monitor);
	n = data->cnt;
	pthread_mutex_unlock(&data->monitor);
	pthread_mutex_lock(&philo->finish_check);
	while (i < n)
	{
		if (philo->finish == 0)
		{
			pthread_mutex_unlock(&philo->finish_check);
			return (0);
		}
		else if (i == n - 1)
		{
			pthread_mutex_unlock(&philo->finish_check);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&philo->finish_check);
	return (0);
}

void	check_finish(t_data *data, t_philo *philo)
{
	int	i;
	int	n;

	pthread_mutex_lock(&data->monitor);
	n = data->cnt;
	pthread_mutex_unlock(&data->monitor);
	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (check_die(data, &philo[i++]))
				return ;
		}
		i = 0;
		while (i < n)
		{
			if (check_must_eat(data, &philo[i++]))
				return ;
		}
	}
}
