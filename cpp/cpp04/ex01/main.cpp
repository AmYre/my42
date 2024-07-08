/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:33:34 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:50:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	Animal *animals[4];

	std::cout << "*****************Creating Animals - Half Dog Half Cat*****************" << std::endl;
	std::endl(std::cout);
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::endl(std::cout);
	std::cout << "*****************Making sounds and Deleting*****************" << std::endl;
	std::endl(std::cout);
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	std::endl(std::cout);
	std::cout << "*****************Testing the Deep copy pass to public*****************" << std::endl;
	std::endl(std::cout);
	Dog dog1 = Dog("Dog");
	dog1.setIdea(0, "Old Idea");
	Dog dog2 = dog1;
	dog2.setIdea(0, "New Idea");
	std::cout << dog1.getIdea(0) << std::endl;
	std::cout << dog2.getIdea(0) << std::endl;

	return (0);
}