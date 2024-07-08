/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:22:33 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/26 00:54:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string level_str = av[1];
	int level = 0;
	if (level_str == "DEBUG")
		level = 1;
	else if (level_str == "INFO")
		level = 2;
	else if (level_str == "WARNING")
		level = 3;
	else if (level_str == "ERROR")
		level = 4;
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	harl.complain(level);
	return (0);
}