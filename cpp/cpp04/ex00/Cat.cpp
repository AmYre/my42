/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:31:18 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:11:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor" << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string type)
{
	std::cout << "Cat type constructor" << std::endl;
	this->type = type;
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
	Animal::operator=(cat);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound : Miaou miaou !" << std::endl;
}