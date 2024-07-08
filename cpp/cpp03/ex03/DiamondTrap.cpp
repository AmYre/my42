/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:33:29 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 02:00:36 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor with name" << std::endl;
	this->name = name;
	ClapTrap::name = name + ClapTrap::name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
	*this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << "DiamondTrap assignation operator" << std::endl;
	this->name = diamondTrap.name;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
	this->attackDamage = diamondTrap.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "💎💎💎 "
				<< "I am "
				<< this->name
				<< " and my ClapTrap name is "
				<< ClapTrap::name
				<< " 💎💎💎" << std::endl;
}