/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:58:02 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:51:26 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);
	virtual ~Dog();

	void makeSound() const;
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
};