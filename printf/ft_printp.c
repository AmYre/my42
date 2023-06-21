/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:59:06 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/21 02:52:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printp(unsigned long int n, int *count)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
		return ;
	}
	*count = *count + 2;
	write(1, "0x", 2);
	ft_printhexa(n, count, 'x');
}
