/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:43:41 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/25 23:52:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
