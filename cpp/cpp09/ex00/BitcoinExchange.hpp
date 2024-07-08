/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:42 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/10 02:39:55 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>

class BitcoinExchange
{
public:
	BitcoinExchange(std::string csvFile);
	~BitcoinExchange();
	void mapExchange();
	void mapValues(std::string inputFile);
	void displayResults();
	std::string trim(const std::string &str);
	bool isValidDate(const std::string &str);

private:
	std::string filename;
	std::multimap<std::string, float> exchange;
	std::multimap<std::string, float> values;
};