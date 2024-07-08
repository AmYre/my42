/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:52:34 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/09 00:47:49 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::invalid_argument("Error: Invalid number of arguments | Usage: ./RPN \"7 7 * 7\"");
		RPN RPN(av[1]);
		if (!RPN.isRPN(av[1]))
			throw std::invalid_argument("Error: Invalid format | Must be in RPN format");
		RPN.rpn();
		std::cout << RPN.getResult() << '\n';
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what() << '\n';
	}

	return (0);
}
