/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:28:07 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 21:04:33 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class AForm;
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
	void signForm(AForm &form);

	void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureau);