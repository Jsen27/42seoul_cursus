/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:44:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/12/24 20:29:44 by sehjung          ###   ########seoul.kr  */
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
	long long				die_time;
	long long				eat_time;
	long long		sleep_time;
	long long		must_eat;	
	pthread_mutex_t *forks;
	pthread_mutex_t print_m;
}t_data;

typedef struct	s_philo
{
	pthread_t	pid;
	t_data		*data;
	int			num;
	int			eat_cnt;
	int			left;
	int			right;
	int			finish;
	long long			last_eat;
}t_philo;

int		init_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *str);
int		error_exit(t_data *data, int error);
int		init_philo(t_data *data, t_philo **philo);
void	*funt(void *arg);
void	start_philo(t_data *data, t_philo *philo);
long long	now_time();
void	print_stats(t_data *data, char *str, int n);
void	clear_sleep(t_data *data, long long time);
