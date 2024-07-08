/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:33:34 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 22:28:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete animal;
	delete dog;
	delete cat;

	//implement a WrongCat class that inherits
	// from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
	// in the code above, the WrongCat should output the WrongAnimal sound.

	WrongAnimal *w_cat1 = new WrongCat();
	WrongCat *w_cat2 = new WrongCat();

	w_cat1->makeSound();
	w_cat2->makeSound();

	return (0);
}