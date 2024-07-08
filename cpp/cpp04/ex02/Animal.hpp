/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:49:17 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 22:14:26 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	virtual ~Animal();
	std::string getType() const;
	virtual void makeSound() const = 0;
};