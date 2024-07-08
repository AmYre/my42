/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:58:30 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:11:16 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string type)
{
	std::cout << "Dog type constructor" << std::endl;
	this->type = type;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy constructor" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignation operator" << std::endl;
	Animal::operator=(dog);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound : Waf waf !" << std::endl;
}
