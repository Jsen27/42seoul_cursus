/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/24 20:31:19 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		i++;
	}
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

static int init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->cnt)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (error_mutex(data, &data->forks[i]));
	}
	if (pthread_mutex_init(&data->print_m, NULL))
	{
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
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->cnt);
	if (!data->forks)
		return (error_exit(data, 1));
	return (init_mutex(data));
}
