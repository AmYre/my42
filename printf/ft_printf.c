/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:02:57 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/26 21:16:32 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printspec(const char *str, va_list *args, int i)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'c')
		count += ft_printchar(va_arg(*args, int));
	else if (str[i + 1] == 's')
		count += ft_printstr(va_arg(*args, char *));
	else if (str[i + 1] == 'p')
		ft_printp((unsigned long int)va_arg(*args, void *), &count);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_printnbr(va_arg(*args, int), &count);
	else if (str[i + 1] == 'u')
		ft_printunbr(va_arg(*args, unsigned int), &count);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		ft_printhexa((unsigned long long int)va_arg(*args, unsigned int),
			&count, str[i + 1]);
	else if (str[i + 1] == '%')
		count += ft_printchar('%');
	i++;
	return (count - 2);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += ft_printspec(str, &args, i);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count + i);
}
