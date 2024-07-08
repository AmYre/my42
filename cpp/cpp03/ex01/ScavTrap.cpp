/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:20:16 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 01:44:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor with name" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
	*this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap assignation operator" << std::endl;
	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "🔫🔫🔫 "
				<< this->name
				<< " attacks "
				<< target
				<< " causing "
				<< this->attackDamage
				<< " points of damage! 🔫🔫🔫" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "🛡️🛡️🛡️ "
				<< this->name
				<< " has entered in Gate keeper mode!"
				<< " 🛡️🛡️🛡️" << std::endl;
}
