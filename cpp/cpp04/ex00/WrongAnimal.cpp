/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:17:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 22:18:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
	: type(type)
{
	std::cout << "WrongAnimal type constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal assignation operator" << std::endl;
	if (this == &wrongAnimal)
		return (*this);
	type = wrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}