/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:30:49 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 22:04:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	virtual ~Cat();
	void makeSound() const;
};