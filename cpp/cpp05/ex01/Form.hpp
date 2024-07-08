/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:49:29 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 21:05:16 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std::string name;
	bool isSigned;
	const int SignerGrade;
	const int ExecutorGrade;

public:
	Form();
	Form(std::string const &name, int signer, int executor);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

	std::string const &getName() const;
	bool getIsSigned() const;
	int getSigner() const;
	int getExecutor() const;
	void setIsSigned();
	void beSigned(Bureaucrat &bureau);
};

std::ostream &operator<<(std::ostream &out, Form const &form);
