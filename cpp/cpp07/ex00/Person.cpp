/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:56:17 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 21:53:31 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Person.hpp"

Person::Person(std::string &name, int age) : name(name), age(age) {}

Person::Person(Person &other)
{
	int tempAge = other.age;
	std::string tempName = other.name;

	other.age = this->age;
	other.name = this->name;

	this->age = tempAge;
	this->name = tempName;
}

Person &Person::operator=(Person &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->age = other.age;
	}
	return *this;
}

Person::~Person() {}

bool Person::operator>(Person &other)
{
	return (this->age > other.age);
}

bool Person::operator<(Person &other)
{
	return (this->age < other.age);
}

std::ostream &operator<<(std::ostream &out, const Person &person)
{
	out << person.age;
	return out;
}