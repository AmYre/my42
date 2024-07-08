/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:13:45 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 01:31:15 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor with name" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	std::cout << "FragTrap copy constructor" << std::endl;
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	std::cout << "FragTrap assignation operator" << std::endl;
	this->name = fragTrap.name;
	this->hitPoints = fragTrap.hitPoints;
	this->energyPoints = fragTrap.energyPoints;
	this->attackDamage = fragTrap.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "👋👋👋 "
				<< this->name
				<< " says : Give me five, Bruh!"
				<< " 👋👋👋" << std::endl;
}
