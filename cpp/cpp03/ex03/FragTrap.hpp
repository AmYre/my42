/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:43:49 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/09 01:31:35 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap();
	FragTrap &operator=(const FragTrap &fragTrap);

	void highFivesGuys(void);
};