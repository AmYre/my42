/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:55:37 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/11 23:08:41 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;37m"
# define RESET	"\033[0m"

typedef struct s_data {
	int				forks;
	int				dead_id;
	long long		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				over;
	pthread_mutex_t	dead_id_mutex;
	pthread_mutex_t	over_mutex;
	pthread_mutex_t	printf_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal_time;
	int				meals;
	pthread_t		thread;
	pthread_mutex_t	meals_mutex;
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	lmt_mutex;
	pthread_mutex_t	fork;
	t_data			*data;
}					t_philo;

long long	ft_atoi(const char *str);
long long	current_time(void);
void		init_data(int argc, char **argv, t_data *data);
void		init_philo(t_philo *philo, t_data *data);
void		*routine(void *arg);
void		thinking(t_philo *philo);
int			eating(t_philo *philo);
void		sleeping(t_philo *philo);
int			is_over(t_philo *philo);
int			check_args(int argc, char **argv);
int			sleep_and_check(long long sleep_time, t_philo *philo);
int			print_status(t_philo *philo, char *icon, char *status);
int			print_simple(t_philo *philo, char *icon, char *status);
void		print_died(t_philo *philo, t_data *data);
int			monitoring(t_philo *philo, t_data *data);
void		*philone(void *arg);
void		free_all(t_philo *philo, t_data data);

#endif
