/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:56:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/11 02:21:57 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv, t_data *data)
{
	pthread_mutex_init(&data->dead_id_mutex, NULL);
	pthread_mutex_init(&data->printf_mutex, NULL);
	pthread_mutex_init(&data->over_mutex, NULL);
	data->forks = ft_atoi(argv[1]);
	data->over = 0;
	data->dead_id = 0;
	data->start_time = current_time();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals = ft_atoi(argv[5]);
	else
		data->max_meals = -1;
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->forks)
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		pthread_mutex_init(&philo[i].lmt_mutex, NULL);
		pthread_mutex_init(&philo[i].meals_mutex, NULL);
		philo[i].id = i + 1;
		philo[i].last_meal_time = current_time();
		philo[i].meals = 0;
		philo[i].data = data;
		i++;
	}
	i = 0;
	while (i < data->forks)
	{
		philo[i].next_fork = &philo[(i + 1) % data->forks].fork;
		i++;
	}
}

void	*philone(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->fork);
	print_simple(philo, "🤤", "has taken a fork");
	usleep(philo->data->time_to_die * 1000);
	print_simple(philo, "😵", "died");
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	free_all(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < data.forks)
	{
		pthread_mutex_destroy(&philo[i].fork);
		pthread_mutex_destroy(&philo[i].lmt_mutex);
		pthread_mutex_destroy(&philo[i].meals_mutex);
		i++;
	}
	pthread_mutex_destroy(&data.dead_id_mutex);
	pthread_mutex_destroy(&data.printf_mutex);
	pthread_mutex_destroy(&data.over_mutex);
	free(philo);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_data		data;
	int			i;

	if (!check_args(argc, argv))
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_data(argc, argv, &data);
	init_philo(philo, &data);
	if (data.forks == 1)
	{
		pthread_create(&philo[0].thread, NULL, &philone, &philo[0]);
		pthread_join(philo[0].thread, NULL);
	}
	else
	{
		i = -1;
		while (++i < data.forks)
			pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		monitoring(philo, &data);
		i = -1;
		while (++i < data.forks)
			pthread_join(philo[i].thread, NULL);
	}
	return (free_all(philo, data), 0);
}
