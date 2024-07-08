/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:54:55 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 02:06:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}