/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/15 18:10:16 by sehjung          ###   ########seoul.kr  */
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
	pthread_t	pid;
	t_data		*data;
	int			num;
	int			eat_cnt;
	int			left;
	int			right;
	struct timeval	last_eat;
}t_philo;

void	init_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
void	error_exit(t_data *data, int error);
void	init_philo(t_data *data, t_philo **philo);
void	*funt(t_philo *philo);
void	start_philo(t_data *data, t_philo *philo);
double	print_time(t_data *data);
