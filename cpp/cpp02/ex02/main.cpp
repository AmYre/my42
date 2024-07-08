/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:25:31 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/06 20:01:19 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(42);
	Fixed d(21);

	std::cout << "---Fractionnal Incremenation---" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "---Comparison---" << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	if (c > d)
		std::cout << "c is greater than d" << std::endl;

	if (c != d)
		std::cout << "c is not equal to d" << std::endl;

	d = c;
	if (c == d)
		std::cout << "c is equal to d" << std::endl;

	std::cout << "---Arithmetic---" << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;
	//std::cout << c / 0 << std::endl;
	return (0);
}