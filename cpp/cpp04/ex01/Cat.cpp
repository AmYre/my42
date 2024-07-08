/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:31:18 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:51:38 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;

	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(std::string type)
{
	std::cout << "Cat type constructor" << std::endl;

	this->type = type;
	brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor" << std::endl;

	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat assignation operator" << std::endl;

	if (this == &cat)
		return (*this);

	delete brain;

	Animal::operator=(cat);
	brain = new Brain(*cat.brain);

	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound : Miaaaou" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea)
{
	brain->setIdea(index, idea);
}
