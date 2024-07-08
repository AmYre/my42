/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:56:13 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:12:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("Animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type)
	: type(type)
{
	std::cout << "Animal type constructor" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal assignation operator" << std::endl;
	if (this == &animal)
		return (*this);
	type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
