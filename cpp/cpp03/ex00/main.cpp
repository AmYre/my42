/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:56:20 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 00:10:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Odin("Odin");
	ClapTrap Thor("Thor");
	ClapTrap Loki("Loki");

	Thor.attack("Loki");
	Loki.takeDamage(Thor.getAttackDamage());
	Thor.attack("Loki");
	Loki.takeDamage(Thor.getAttackDamage());
	Loki.beRepaired(std::rand() % 5 + 1);
	Loki.attack("Thor");
	Thor.takeDamage(Loki.getAttackDamage());

	while (Thor.getHitPoints() > 0 && Loki.getHitPoints() > 0)
	{
		Odin.attack("Thor");
		Thor.takeDamage(Odin.getAttackDamage());
		Odin.attack("Loki");
		Loki.takeDamage(Odin.getAttackDamage());
	}

	return (0);
}