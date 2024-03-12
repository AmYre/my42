/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:25:25 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/12 00:43:27 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_thinking(t_philo *philo)
{
	print_status(philo, "🥸", "is thinking");
	// usleep((philo->data->time_to_die
	// 		- (philo->data->time_to_eat
	// 			+ philo->data->time_to_sleep + 10)) * 1000);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (!is_over(philo))
			break ;
		if (!eating(philo))
			break ;
		if (!print_status(philo, "💤", "is sleeping"))
			break ;
		if (!sleep_and_check(philo->data->time_to_sleep
				* 1000, philo))
			break ;
		if (!is_thinking(philo))
			break ;
	}
	return (NULL);
}

void	fork_taking(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		print_status(philo, "🤤", "has taken a fork");
		pthread_mutex_lock(philo->next_fork);
		print_status(philo, "🤤", "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->next_fork);
		print_status(philo, "🤤", "has taken a fork");
		pthread_mutex_lock(&philo->fork);
		print_status(philo, "🤤", "has taken a fork");
	}
}

int	eating(t_philo *philo)
{
	if (!is_over(philo))
		return (0);
	fork_taking(philo);
	print_status(philo, "🍕", "is eating");
	pthread_mutex_lock(&philo->lmt_mutex);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->lmt_mutex);
	pthread_mutex_lock(&philo->meals_mutex);
	philo->meals++;
	pthread_mutex_unlock(&philo->meals_mutex);
	if (!sleep_and_check(philo->data->time_to_eat * 1000LL, philo))
		return (pthread_mutex_unlock(&philo->fork),
			pthread_mutex_unlock(philo->next_fork), 0);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
	return (1);
}

int	is_over(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->over_mutex);
	pthread_mutex_lock(&philo->meals_mutex);
	if (philo->data->over == 1
		|| (philo->meals >= philo->data->max_meals
			&& philo->data->max_meals != -1))
		return (pthread_mutex_unlock(&philo->meals_mutex),
			pthread_mutex_unlock(&philo->data->over_mutex), 0);
	pthread_mutex_unlock(&philo->meals_mutex);
	pthread_mutex_unlock(&philo->data->over_mutex);
	pthread_mutex_lock(&philo->data->over_mutex);
	if (philo->data->over)
		return (pthread_mutex_unlock(&philo->data->over_mutex), 0);
	pthread_mutex_unlock(&philo->data->over_mutex);
	return (1);
}
