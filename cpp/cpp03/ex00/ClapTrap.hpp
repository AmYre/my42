/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:25:32 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 00:10:34 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

class ClapTrap
{
  private:
	std::string name;
	int hitPoints; //health
	int energyPoints;
	int attackDamage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &clapTrap);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setName(std::string name);
	void setAttackDamage(int attackDamage);
	std::string getName();
	int getHitPoints();
	int getEnergyPoints();
	int getAttackDamage();
};