/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:08:53 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 20:56:41 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int SignerGrade;
	const int ExecutorGrade;

public:
	AForm();
	AForm(std::string const &name, int signer, int executor);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();

	std::string const &getName() const;
	bool getIsSigned() const;
	void setIsSigned();
	int getSigner() const;
	int getExecutor() const;
	void beSigned(Bureaucrat &bureau);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);
