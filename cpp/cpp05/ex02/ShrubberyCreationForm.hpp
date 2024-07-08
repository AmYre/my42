/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:10:06 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 19:34:37 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const &executor) const;
};