/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:02 by sehjung           #+#    #+#             */
/*   Updated: 2023/01/05 17:06:15 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_stdin(t_data *data)
{
	if (data->cnt < 1 || data->die_time < 1 || data->eat_time < 1)
		return (error_exit(data, 0));
	if (data->sleep_time < 1)
		return (error_exit(data, 0));
	return (0);
}

static int	error_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (&data->forks[i] != forks)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	return (error_exit(data, 1));
}

int	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * data->cnt);
	if (!philo)
		return (error_mutex(data, &data->forks[data->cnt]));
	while (i < data->cnt)
	{
		(*philo)[i].data = data;
		(*philo)[i].num = i;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % data->cnt;
		(*philo)[i].finish = 0;
		(*philo)[i].last_eat = 0;
		pthread_mutex_init(&(*philo)[i].finish_check, NULL);
		i++;
	}
	return (0);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (error_mutex(data, &data->forks[i]));
		i++;
	}
	if (pthread_mutex_init(&data->print_m, NULL))
		return (error_mutex(data, &data->forks[data->cnt]));
	if (pthread_mutex_init(&data->monitor, NULL))
	{
		pthread_mutex_destroy(&data->print_m);
		return (error_mutex(data, &data->forks[data->cnt]));
	}
	if (pthread_mutex_init(&data->die_m, NULL))
	{
		pthread_mutex_destroy(&data->monitor);
		pthread_mutex_destroy(&data->print_m);
		return (error_mutex(data, &data->forks[data->cnt]));
	}
	return (0);
}

int	init_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (error_exit(data, 0));
	data->cnt = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->finish_check = 0;
	data->die_check = 0;
	if (error_stdin(data))
		return (1);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->cnt);
	if (!data->forks)
		return (error_exit(data, 1));
	return (init_mutex(data));
}
