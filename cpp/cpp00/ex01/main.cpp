/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:30:36 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/25 01:31:24 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "Welcome to the -CAPS- Crappy Awesome Phonebook Software" << std::endl;
	std::cout << "Please enter a command [ADD, SEARCH, EXIT]" << std::endl;;
	std::getline(std::cin, input);
	while (input != "EXIT" && std::cin.good())
	{
		if (input.empty())
		{
			std::cout << "Please enter a command [ADD, SEARCH, EXIT]" << std::endl;
		}
		else if (input == "ADD")
		{
			phonebook.add_contact();
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.get_flag() && !phonebook.get_nbr_of_contacts())
			{
				std::cout << "No contacts available" << std::endl;
				std::cout << "You can add one with [ADD] command" << std::endl;
			}
			else
				phonebook.search_contact();
		}
		else
		{
			std::cout << "Invalid command, accepts [ADD, SEARCH, EXIT]" << std::endl;
		}
		std::getline(std::cin, input);
	}
	return (0);
}