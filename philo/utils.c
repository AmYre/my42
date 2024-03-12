/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:24:06 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/11 23:08:05 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_and_check(long long sleep_time, t_philo *philo)
{
	struct timeval	time;
	long long		end_time;
	long long		start;

	(void)philo;
	gettimeofday(&time, NULL);
	end_time = time.tv_sec * 1000000 + time.tv_usec + sleep_time;
	start = 0;
	while (start < end_time)
	{
		if (!is_over(philo))
			return (0);
		usleep(500);
		gettimeofday(&time, NULL);
		start = time.tv_sec * 1000000 + time.tv_usec;
	}
	return (1);
}

int	print_status(t_philo *philo, char *icon, char *status)
{
	char	*colors[5];

	colors[0] = GREEN;
	colors[1] = YELLOW;
	colors[2] = RED;
	colors[3] = CYAN;
	colors[4] = MAGENTA;
	if (!is_over(philo))
		return (0);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("🕜 %lld - %s philo %s#%d %s %s\n",
		current_time() - philo->data->start_time,
		icon, colors[philo->id % 5], philo->id, status, RESET);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	return (1);
}

int	print_simple(t_philo *philo, char *icon, char *status)
{
	char	*colors[5];

	colors[0] = GREEN;
	colors[1] = YELLOW;
	colors[2] = RED;
	colors[3] = CYAN;
	colors[4] = MAGENTA;
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("🕜 %lld - %s philo %s#%d %s %s\n",
		current_time() - philo->data->start_time,
		icon, colors[philo->id % 5], philo->id, status, RESET);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	return (1);
}

long long	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error: timestamp failed\n");
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	nbr;
	int			sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
