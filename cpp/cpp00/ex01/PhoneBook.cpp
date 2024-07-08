/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:19:39 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/25 01:31:02 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	flag = 0;
	nbr_of_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	std::string input_first_name;
	std::string input_last_name;
	std::string input_nickname;
	std::string input_phone_number;
	std::string input_darkest_secret;

	if (flag && !nbr_of_contacts)
	{
		std::cout << "Phonebook is full, oldest entry overrided" << std::endl;
	}
	std::cout << "Please enter the first name: ";
	while (input_first_name.empty()){
		std::getline(std::cin, input_first_name);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		while (input_first_name.find('\t') != std::string::npos)
			input_first_name.replace(input_first_name.find('\t'), 1, " ");
		if (input_first_name.empty()) {
			std::cout << "It's empty! Enter a value this time: ";
		}
	}
	std::cout << "Please enter the last name: ";
	while (input_last_name.empty()){
		std::getline(std::cin, input_last_name);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		while (input_last_name.find('\t') != std::string::npos)
			input_last_name.replace(input_last_name.find('\t'), 1, " ");
		if (input_last_name.empty()) {
			std::cout << "It's empty! Enter a value this time: ";
		}
	}
	std::cout << "Please enter the nickname: ";
	while (input_nickname.empty()){
		std::getline(std::cin, input_nickname);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		while (input_nickname.find('\t') != std::string::npos)
			input_nickname.replace(input_nickname.find('\t'), 1, " ");
		if (input_nickname.empty()) {
			std::cout << "It's empty! Enter a value this time: ";
		}
	}
	std::cout << "Please enter the phone number: ";
	while (input_phone_number.empty()){
		std::getline(std::cin, input_phone_number);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		if (input_phone_number.find('\t') != std::string::npos)
			input_phone_number.replace(input_phone_number.find('\t'), 1, " ");
		if (input_phone_number.empty()) {
			std::cout << "It's empty! Enter a value this time: ";
		}
	}
	std::cout << "Please enter the darkest secret: ";
	while (input_darkest_secret.empty()){
		std::getline(std::cin, input_darkest_secret);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		while (input_darkest_secret.find('\t') != std::string::npos)
			input_darkest_secret.replace(input_darkest_secret.find('\t'), 1, " ");
		if (input_darkest_secret.empty()) {
			std::cout << "It's empty! Enter a value this time: ";
		}
	}
	Contact contact(input_first_name, input_last_name, input_nickname, input_phone_number, input_darkest_secret);
	this->contact[nbr_of_contacts % 8] = contact;
	this->nbr_of_contacts++;
	if (nbr_of_contacts && nbr_of_contacts == 7)
		flag = 1;
	std::cout << std::endl;
	std::cout << "**============CAPS============**" << std::endl;
	std::cout << std::endl;
	std::cout << "Contact added" << std::endl;
	std::cout << std::endl;
	std::cout << "**============CAPS============**" << std::endl;
	std::cout << std::endl;
	std::cout << "Please enter a command to continue [ADD, SEARCH, EXIT]" << std::endl;
}

void	PhoneBook::search_contact()
{
	for (int i = 0; i < 8; i++)
	{
		std::string first_name = contact[i].get_first_name();
		std::string last_name = contact[i].get_last_name();
		std::string nickname = contact[i].get_nickname();
		std::cout << std::setw(10) << i << " | ";
		std::cout << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << " | ";
		std::cout << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << " | ";
		std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << " | " << std::endl;
	}
	std::cout << "Enter index contact you want to see: ";
	std::string index;
	while (index.empty() || index != "0" || index != "1" || index != "2" || index != "3" || index != "4" || index != "5" || index != "6" || index != "7") {
		std::getline(std::cin, index);
		if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
			std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
			return ;
		}
		if (index == "0" || index == "1" || index == "2" || index == "3" || index == "4" || index == "5" || index == "6" || index == "7")
		{
			int i;
			if (index == "0")
				i = 0;
			if (index == "1")
				i = 1;
			if (index == "2")
				i = 2;
			if (index == "3")
				i = 3;
			if (index == "4")
				i = 4;
			if (index == "5")
				i = 5;
			if (index == "6")
				i = 6;
			if (index == "7")
				i = 7;
			if (i < nbr_of_contacts) {

				std::cout << std::endl;
				std::cout << "**============CAPS============**" << std::endl;
				std::cout << std::endl;
				std::cout << "First name: " << contact[i].get_first_name() << std::endl;
				std::cout << "Last name: " << contact[i].get_last_name() << std::endl;
				std::cout << "Nickname: " << contact[i].get_nickname() << std::endl;
				std::cout << "Phone number: " << contact[i].get_phone_number() << std::endl;
				std::cout << "Darkest secret: " << contact[i].get_darkest_secret() << std::endl;
				std::cout << std::endl;
				std::cout << "**============CAPS============**" << std::endl;
				std::cout << std::endl;
				std::cout << "Please enter a command to continue [ADD, SEARCH, EXIT]" << std::endl;
				break;
			} else {
				std::cout << "No contact at this index, try again" << std::endl;
			}
		}
		else
			std::cout << "Invalid index, try again" << std::endl;
	}
}

void	PhoneBook::check_contact(std::string input)
{
	if (std::cin.eof() || std::cin.bad() || std::cin.fail()) {
		std::cout << std::endl << "-CAPS- Crappy Awesome PhoneBook Software exited by EOF" << std::endl;
		return ;
	}
	if (input.empty()) {
		std::cout << "It's empty! Enter a value this time: ";
	}
}

int	PhoneBook::get_flag()
{
	return (flag);
}

int	PhoneBook::get_nbr_of_contacts()
{
	return (nbr_of_contacts);
}