/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:19:38 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 22:20:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type)
	: WrongAnimal(type)
{
	std::cout << "WrongCat type constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << "WrongCat assignation operator" << std::endl;
	if (this == &wrongCat)
		return (*this);
	type = wrongCat.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound : Miaaaaouss oui la guerre !" << std::endl;
}