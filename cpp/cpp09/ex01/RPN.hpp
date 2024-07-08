/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:52:48 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/09 01:48:33 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN
{
private:
	std::string str;
	int result;
	std::stack<int> values;

public:
	RPN();
	RPN(std::string str);
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);

	void rpn();
	bool isRPN(std::string str);
	void calculate(std::stack<int> &stack, char op);
	int getResult() const;
};