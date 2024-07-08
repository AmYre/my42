/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:23:01 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/26 00:30:17 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Harl
{
public:
	void complain(std::string level);
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};