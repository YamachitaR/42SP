/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:29:41 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/12/12 11:24:08 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# include<pthread.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5
# define FULL 6
# define DINNER 7
# define OFF 8

typedef struct s_philo
{
	int				id;
	long			time_start;
	long			time_meal;
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_eat;
	pthread_mutex_t	*fork_first;
	pthread_mutex_t	*fork_second;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	mutex_philo;
	pthread_mutex_t	mutex_time;
	int				status;
}t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_t		*pthread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
}t_data;

long		ft_atoi(char *str);
long		ft_time_epoch_in_ms(void);
int			ft_argv_check(int argc, char **argv);
int			ft_data_init(t_data **data, char **argv);
int			ft_philo_init(t_philo **philo, t_data **data);
void		*ft_philo(void *arg);
int			ft_print(t_philo *philo, int flag);
int			ft_philo_pthread(t_philo *philo, t_data *data);
int			ft_clean(t_data *data, t_philo *philo);
long		ft_time_epoch_in_ms(void);
int			ft_error_malloc(void);
int			ft_error_mutex(void);
int			ft_error_pthread(void);
int			ft_mutex_get(int *get, pthread_mutex_t *mutex);
void		ft_mutex_set(int *nbr, pthread_mutex_t *mutex, int value);
long int	ft_mutex_get_time(long int *time, pthread_mutex_t *mutex);
void		ft_mutex_set_time(long int *nbr,
				pthread_mutex_t *mutex, long int value);
int			ft_philo_eat(t_philo *philo);
int			ft_philo_think(t_philo *philo);
int			ft_philo_sleep(t_philo *philo);
int			ft_monitoring(t_philo *philo, int size, long int time_life);

#endif
