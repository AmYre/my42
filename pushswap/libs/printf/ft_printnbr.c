/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:15:43 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/21 02:35:45 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int n, int *count)
{
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
		(*count)++;
	}
	if (nbr >= 10)
		ft_printnbr(nbr / 10, count);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
	(*count)++;
}
