/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:19:05 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 02:03:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap("Clappy");
	FragTrap fragTrap("Fraggy");
	ScavTrap scavTrap("Scavvy");
	DiamondTrap diamondTrap("Diammy");

	std::cout << "🤖🤖🤖 " << clapTrap.getName() << " 🤖🤖🤖" << std::endl;
	clapTrap.attack("himself");
	clapTrap.takeDamage(0);
	clapTrap.beRepaired(5);
	std::cout << " health: " << clapTrap.getHitPoints() << std::endl;

	std::cout << "🤖🤖🤖 " << fragTrap.getName() << " 🤖🤖🤖" << std::endl;
	scavTrap.attack("himself");
	scavTrap.takeDamage(20);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	std::cout << " health: " << scavTrap.getHitPoints() << std::endl;

	std::cout << "🤖🤖🤖 " << scavTrap.getName() << " 🤖🤖🤖" << std::endl;
	fragTrap.attack("himself");
	fragTrap.takeDamage(30);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	std::cout << " health: " << fragTrap.getHitPoints() << std::endl;

	std::cout << "🤖🤖🤖 "
				<< "Diammy"
				<< " 🤖🤖🤖" << std::endl;
	std::cout << " Hit points: " << diamondTrap.getHitPoints() << std::endl;
	std::cout << " Energy points: " << diamondTrap.getEnergyPoints() << std::endl;
	std::cout << " Attack damage: " << diamondTrap.getAttackDamage() << std::endl;
	diamondTrap.attack("himself");
	diamondTrap.takeDamage(30);
	diamondTrap.beRepaired(5);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	std::cout << " health: " << diamondTrap.getHitPoints() << std::endl;

	return (0);
}