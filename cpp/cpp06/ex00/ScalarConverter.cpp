/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:59:59 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/29 23:18:00 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <exception>
#include <typeinfo>

ScalarConverter::ScalarConverter()
{
}

void ScalarConverter::convert(std::string const &str)
{
	std::cout << "char: ";
	if (std::isalpha(str[0]) && str.length() == 1)
	{
		char c = static_cast<char>(str[0]);
		// std::cout << "type = " << typeid(c).name() << std::endl;
		std::cout << "'" << c << "'" << std::endl;
	}
	else
	{
		int temp = std::atoi(str.c_str());
		// std::cout << "type = " << typeid(temp).name() << std::endl;
		if (temp >= std::numeric_limits<char>::min() && temp <= std::numeric_limits<char>::max())
		{
			char c = static_cast<char>(temp);
			if (isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else
				std::cout << "Non displayable char" << std::endl;
		}
		else
		{
			std::cout << "Range for this char is invalid" << std::endl;
		}
	}
	std::cout << "int: ";
	if (std::isalpha(str[0]) && str.length() == 1 && (str[0] >= std::numeric_limits<char>::min() && str[0] <= std::numeric_limits<char>::max()))
	{
		// std::cout << "type = " << typeid(static_cast<int>(str[0])).name() << std::endl;
		std::cout << static_cast<int>(str[0]) << std::endl;
	}
	else
	{
		// std::cout << "type = " << typeid(static_cast<int>(str[0])).name() << std::endl;
		std::cout << static_cast<int>(std::atoi(str.c_str())) << std::endl;
	}
	// std::cout << "type = " << typeid(static_cast<float>(std::atof(str.c_str()))).name() << std::endl;
	std::cout << "float: " << static_cast<float>(std::atof(str.c_str())) << "f" << std::endl;
	// std::cout << "type = " << typeid(static_cast<double>(std::atof(str.c_str()))).name() << std::endl;
	std::cout << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
}