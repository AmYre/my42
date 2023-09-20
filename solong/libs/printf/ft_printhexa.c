/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:26:47 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/21 00:23:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned long long int n, int *count, char spec)
{
	char	hexa;

	if (spec == 'x')
		hexa = 'a';
	else
		hexa = 'A';
	if (n >= 16)
	{
		ft_printhexa(n / 16, count, spec);
		ft_printhexa(n % 16, count, spec);
	}
	else
	{
		if (n < 10)
			ft_printchar(n + '0');
		else if (n >= 10)
			ft_printchar((n - 10) + hexa);
		(*count)++;
	}
}
