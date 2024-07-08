/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:44 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/06 22:06:52 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Error: needs one input file as argument.");

		BitcoinExchange exchange("data.csv");
		exchange.mapExchange();
		exchange.mapValues(argv[1]);
		exchange.displayResults();
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
	return 0;
}