/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:58:30 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:51:47 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor" << std::endl;

	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(std::string type)
{
	std::cout << "Dog type constructor" << std::endl;

	this->type = type;
	brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy constructor" << std::endl;
	brain = new Brain(*dog.brain);
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog assignation operator" << std::endl;

	if (this != &dog)
	{
		delete brain;

		brain = new Brain(*dog.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound : Waf waf !" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}

void Dog::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}