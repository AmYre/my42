/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:00:36 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/29 23:08:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Bad usage of the convert program" << std::endl;
		std::cout << "The good usage is: ./convert <value>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}