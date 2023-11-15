/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:04:10 by amben-ha          #+#    #+#             */
/*   Updated: 2023/06/21 00:23:20 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printchar(char c);
int		ft_printstr(char *str);
void	ft_printp(unsigned long int n, int *count);
void	ft_printnbr(int nbr, int *count);
void	ft_printunbr(unsigned int nbr, int *count);
void	ft_printhexa(unsigned long long int nbr, int *count, char spec);
int		ft_printf(const char *format, ...);

#endif
