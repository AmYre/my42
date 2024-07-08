/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:10:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 18:47:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}