/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:08:53 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 01:44:51 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &scavTrap);

	void attack(std::string const &target);
	void guardGate();
};