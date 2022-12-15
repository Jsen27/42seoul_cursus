/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/15 17:55:36 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * data->cnt);
	if (!philo)
		error_exit(data, 2);
	while (i < data->cnt)
	{
		(*philo)[i].data = data;
		(*philo)[i].num = i;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % data->cnt;
		i++;
	}
}

static void	error_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (&data->forks[i] != forks)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	error_exit(data, 1);
}

void	init_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		error_exit(data, 0);
	data->cnt = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_time = ft_atoi(argv[5]);
	else
		data->must_eat_time = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->cnt);
	if (!data->forks)
		error_exit(data, 2);
	while (i < data->cnt)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			error_mutex(data, &data->forks[i]);
		i++;
	}
	gettimeofday(&data->first_time, NULL);
}
