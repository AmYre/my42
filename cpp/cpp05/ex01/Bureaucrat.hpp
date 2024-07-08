/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:28:07 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 19:42:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Exceptions.hpp"
#include "Form.hpp"

class Form;
class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureau);