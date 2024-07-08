/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:13:44 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 03:07:35 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Zombie";
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " n°" << this->nbr << " is dead" << std::endl;
}

void Zombie::announce(std::string name, int nbr)
{
	this->nbr = nbr;
	std::cout << name << " n°" << nbr <<  " : BraiiiiiiinnnzzzZ..." << std::endl;
}
