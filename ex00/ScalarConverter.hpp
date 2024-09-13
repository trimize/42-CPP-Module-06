/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: to <to@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:39:41 by to                #+#    #+#             */
/*   Updated: 2024/08/19 20:03:12 by to               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <sstream>
#include <iostream>
#include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter &s);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &s);
		static void	convert(std::string num);
};

#endif