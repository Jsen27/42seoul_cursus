/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/12 17:59:58 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_data
{
	pthread_t		*philo;
	int				cnt;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_time;	
	pthread_mutex_t *forks;
	struct timeval	first_time;
	struct timeval	now_time;
}t_data;

void	args_init(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
void	error_exit(t_data *data, int error);

