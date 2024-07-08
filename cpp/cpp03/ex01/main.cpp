/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:15:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 01:44:04 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scavTrap("Sereena");
	ClapTrap clapTrap("Williams");

	scavTrap.attack("Williams");
	scavTrap.beRepaired(10);
	scavTrap.guardGate();

	std::cout << scavTrap.getHitPoints() << std::endl;
	std::cout << scavTrap.getEnergyPoints() << std::endl;
	std::cout << scavTrap.getAttackDamage() << std::endl;

	clapTrap.attack("Sereena");
	return (0);
}