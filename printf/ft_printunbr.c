/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:16:50 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/26 20:36:03 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunbr(unsigned int n, int *count)
{
	long long int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_printunbr(nbr / 10, count);
	nbr = nbr % 10 + '0';
	write(1, &nbr, 1);
	(*count)++;
}
