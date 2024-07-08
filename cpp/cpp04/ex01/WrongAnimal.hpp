/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:16:01 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 23:56:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
  protected:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
	virtual ~WrongAnimal();
	std::string getType() const;
	void makeSound() const;
};