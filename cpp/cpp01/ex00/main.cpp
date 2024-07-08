/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:59:16 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Zombie Heap");
	zombie->announce();

	delete zombie;
	randomChump("Zombie Stack");

	std::cout << "Fin du scop global" << std::endl;
	return (0);
}