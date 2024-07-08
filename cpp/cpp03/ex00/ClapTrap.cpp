/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:37:53 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 00:16:45 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor with name" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap assignation operator" << std::endl;
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "😧🥱😴 "
					<< "No energy points left to attack!"
					<< " 😴🥱😧" << std::endl;
		return ;
	}
	this->attackDamage = std::rand() % 5 + 1;
	std::cout << "💥💥💥 " << this->name << " attack " << target << " causing " << this->attackDamage << " points of damage!"
				<< " 💥💥💥" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "🤕🤕🤕 " << this->name << " took " << amount << " points of damage!"
				<< " 🤕🤕🤕" << std::endl;
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
	{
		this->hitPoints = 0;
		std::cout << "💀💀💀 " << this->name << " is dead!"
					<< " 💀💀💀" << std::endl;
	}
	else
		std::cout << "❤️❤️❤️"
					<< this->name << " Health is now: " << this->hitPoints << "❤️❤️❤️" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "😧🥱😴"
					<< "No energy points left to repair!"
					<< " 😴🥱😧" << std::endl;
		return ;
	}
	if (this->hitPoints + amount > 10)
	{
		this->hitPoints = 10;
		std::cout << "⭐⭐⭐ " << this->name << " is fully repaired!"
					<< " ⭐⭐⭐" << std::endl;
		std::cout << "❤️❤️❤️ "
					<< this->name << " Health is now: " << this->hitPoints << " ❤️❤️❤️" << std::endl;
	}
	else
	{
		this->hitPoints += amount;
		std::cout << "✨💉❤️‍🩹 " << this->name << " is repaired by " << amount << " points!"
					<< " ❤️‍🩹💉✨" << std::endl;
		std::cout << "❤️❤️❤️ "
					<< this->name << " Health is now: " << this->hitPoints << " ❤️❤️❤️" << std::endl;
	}
	this->energyPoints--;
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName()
{
	return (this->name);
}

int ClapTrap::getHitPoints()
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}
