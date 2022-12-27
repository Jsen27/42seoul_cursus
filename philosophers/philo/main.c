/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:39 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/27 17:15:53 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(t_data *data, int error)
{
	if (error == 0)
	{
		printf("Usage : ./philosophers number_of_philosophers ");
		printf("time_to_die time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
	else
	{
		printf("Init error !\n");
		free(data->forks);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	if (init_args(argc, argv, &data) || init_philo(&data, &philo))
		return (-1);
	if (philosophers(&data, philo))
		return (-1);
	return (0);
}
