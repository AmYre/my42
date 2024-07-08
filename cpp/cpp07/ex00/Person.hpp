/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:27:59 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 21:53:39 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Person
{
public:
	std::string name;
	int age;

	Person(std::string &name, int age);
	Person(Person &other);
	Person &operator=(Person &other);
	~Person();

	bool operator>(Person &other);
	bool operator<(Person &other);
};

std::ostream &operator<<(std::ostream &out, const Person &person);