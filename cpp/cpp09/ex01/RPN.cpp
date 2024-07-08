/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:55:46 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/09 01:50:20 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : str(""), result(0), values()
{
}

RPN::RPN(std::string str) : str(str), result(0), values()
{
}

RPN::RPN(const RPN &other) : str(other.str), result(other.result), values(other.values)
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);
	str = other.str;
	result = other.result;
	values = other.values;
	return (*this);
}

void RPN::rpn()
{
	std::stack<int> stack;
	std::string ops = "+-*/";
	std::string::size_type i = 0;

	while (i < str.size())
	{
		while (ops.find(str[i]) == std::string::npos)
		{
			if (str[i] == ' ')
			{
				i++;
				continue;
			}
			if (str[i] < '0' || str[i] > '9')
				throw std::invalid_argument("Error: Invalid number | Must be between 0 and 9");
			stack.push(str[i] - '0');
			i++;
		}
		calculate(stack, str[i]);
		i++;
	}
	this->result = stack.top();
}

bool RPN::isRPN(std::string str)
{
	int i = 0;
	int nbr = 0;
	int op = 0;

	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			op++;
			i++;
		}
		else
		{
			while (str[i] && str[i] != ' ')
			{
				if (str[i] < '0' || str[i] > '9')
					return (false);
				i++;
			}
			nbr++;
		}
	}
	if (nbr - 1 != op)
		return (false);
	return (true);
}

void RPN::calculate(std::stack<int> &stack, char op)
{
	int a;
	int b;

	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	switch (op)
	{
	case '/':
		if (a == 0)
			throw std::invalid_argument("Error: Division by zero");
		stack.push(b / a);
		break;
	case '+':
		stack.push(b + a);
		break;
	case '-':
		stack.push(b - a);
		break;
	case '*':
		stack.push(b * a);
		break;
	}
}

int RPN::getResult() const
{
	return (result);
}
