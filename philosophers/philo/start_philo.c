/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:10:22 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/13 21:20:25 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*funt(t_philo *philo)
{
	
}

void	start_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->cnt)
	{
		pthread_create(&philo[i].pid, NULL, funt, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->cnt)
		pthread_join(philo[i++].pid, NULL);
}
