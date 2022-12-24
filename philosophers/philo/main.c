/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:30:39 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/24 20:31:33 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(t_data *data, int error)
{
	if (error == 0)
		printf("Usage : ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else if (error > 0)
	{
		printf("Init error !\n");
			free(data->forks);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo *philo;

	if (init_args(argc, argv, &data) || init_philo(&data, &philo))
		return (-1);
	start_philo(&data, philo);
	
	return (0);
}
