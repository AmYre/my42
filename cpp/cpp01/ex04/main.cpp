/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:12:06 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/27 18:50:13 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments [FILE - String to replace - String to be replaced with]" << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(argv[1]);
	bool isEmpty = true;
	if (!file.is_open())
	{
		std::cout << "An error occurred with the given file" << std::endl;
		return (1);
	}
	std::string newfilename = "result";
	std::ofstream newfile(newfilename.data());
	if (!newfile.is_open())
	{
		std::cout << "Error creating new file" << std::endl;
		return (1);
	}
	if (s1.empty() || s2.empty()) {
		std::cout << "Replacement strings cannot be empty" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (!line.empty()) {
			isEmpty = false;
		}
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		newfile << line << std::endl;
	}
	if (isEmpty) {
		std::cout << "File is empty" << std::endl;
		return (1);
	}
	if (!newfile) {
		std::cout << "Error writing to new file" << std::endl;
		return 1;
	}
	file.close();
	newfile.close();
	return (0);
}