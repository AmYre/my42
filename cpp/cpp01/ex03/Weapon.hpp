/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:42:37 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/25 23:48:40 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string const &getType();
		void setType(std::string type);
	private:
		std::string type;
};