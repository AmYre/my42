/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:48:52 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/11 02:06:52 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_died(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->over_mutex);
	data->over = 1;
	pthread_mutex_unlock(&data->over_mutex);
	pthread_mutex_lock(&philo->meals_mutex);
	if (!(philo->meals >= philo->data->max_meals
			&& philo->data->max_meals != -1))
		print_simple(philo, "😵", "died");
	pthread_mutex_unlock(&philo->meals_mutex);
}

int	monitoring(t_philo *philo, t_data *data)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < data->forks)
		{
			pthread_mutex_lock(&philo[i].lmt_mutex);
			if ((current_time() - philo[i].last_meal_time) > data->time_to_die)
			{
				print_died(philo, data);
				pthread_mutex_unlock(&philo[i].lmt_mutex);
				return (0);
			}
			pthread_mutex_unlock(&philo[i].lmt_mutex);
			i++;
		}
		usleep(500);
	}
	return (1);
}
