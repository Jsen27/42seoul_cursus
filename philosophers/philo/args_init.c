/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/11 21:37:37 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_pthread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(pthread_t) * data->cnt);
	while (i < data->cnt)
	{
		pthread_create(&data->philo[i], NULL, NULL, NULL);
		
	}
}

void	args_init(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (error_exit(0));
	data->cnt = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_time = ft_atoi(argv[5]);
	
}
