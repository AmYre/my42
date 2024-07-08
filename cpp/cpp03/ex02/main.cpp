/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:19:05 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 00:26:01 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap("Clappy");
	FragTrap fragTrap("Fraggy");
	ScavTrap scavTrap("Scavvy");

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

	return (0);
}