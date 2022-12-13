/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/12 21:44:27 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct	s_data
{
	int				cnt;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_time;	
	pthread_mutex_t *forks;
	struct timeval	first_time;
	struct timeval	now_time;
}t_data;

typedef struct	s_philo
{
	pthread_t	*philo;
	t_data		*data;
	int			eat_cnt;
	int			left;
	int			right;
	struct timeval	last_eat;
}t_philo;

void	init_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
void	error_exit(t_data *data, int error);
void	init_philo(t_data *data, t_philo *philo);
