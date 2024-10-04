/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:39:41 by to                #+#    #+#             */
/*   Updated: 2024/10/04 17:38:03 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <ctype.h>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &s);
		ScalarConverter	&operator=(ScalarConverter const &s);
		~ScalarConverter();
	public:
		static void	convert(std::string num);
};

#endif