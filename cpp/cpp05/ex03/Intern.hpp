/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:47:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 21:08:37 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class AForm;
class Intern
{
private:
	AForm *makeShrubForm(std::string const &target);
	AForm *makeRobotForm(std::string const &target);
	AForm *makePrezForm(std::string const &target);

public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();

	AForm *makeForm(std::string const &formName, std::string const &target);
};