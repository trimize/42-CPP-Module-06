/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:59:37 by to                #+#    #+#             */
/*   Updated: 2024/10/04 17:49:40 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter &s)
{
	*this = s;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &s)
{
	(void)s;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

void	ScalarConverter::convert(std::string num)
{
	char	cnum;
	long double ldnum;
	double	dnum;
	int	inum;
	float	fnum;
	bool	number = true;
	bool	decimal = false;

	int i = 0;
	while (num[i])
	{
		if ((num[i] > 57 || num[i] < 48) && num[i] != '.')
			number = false;
		if (num[i] == '.')
			decimal = true;
		i++;
	}
	std::stringstream snum;

	snum << num;
	snum >> ldnum;
	char c = num.at(0);
	if (num.empty())
	{
		std::cout<< "char : Impossible" << std::endl;
		std::cout << "int : Impossible" << std::endl;
		std::cout << "float : Impossible" << std::endl;
		std::cout << "double : Impossible" << std::endl;
	}
	else
	{
		//convert to char
		
		if (num.length() == 1 && std::isprint(c))
			std::cout << "char : " << "'" << c << "'" << std::endl;
		else if ((ldnum > 127) || decimal || num[1] > 57 || num[1] < 48)
			std::cout<< "char : Impossible" << std::endl;
		else if ((0 < ldnum && ldnum <= 32) || (ldnum == 127) || (ldnum <= 0))
			std::cout<< "char : Non displayable" << std::endl;
		else
		{
			cnum = ldnum;
			std::cout << "char : " << "'" << cnum << "'" << std::endl;
		}

		//convert to int

		if (ldnum > 2147483647 || ldnum < -2147483648 || !number || decimal)
			std::cout << "int : Impossible" << std::endl;
		else
		{
			inum = static_cast<int>(ldnum);
			std::cout << "int : " << inum << std::endl;
		}

		//convert to float
		if (num.compare("-inff") == 0)
			std::cout << "float :: -inff" << std::endl;
		else if (num.compare("+inff") == 0)
			std::cout << "float :: +inff" << std::endl;
		else if (num.compare("nan") == 0)
			std::cout << "float :: nanf" << std::endl;
		else if ((num.length() == 1 && std::isprint(c) && (c > 57 || c < 48)) || !number)
			std::cout << "float :: Impossible" << std::endl;
		else if (ldnum >= std::numeric_limits<float>::infinity())
			std::cout << "float :: +inff" << std::endl;
		else if (ldnum <= -std::numeric_limits<float>::infinity())
			std::cout << "float :: -inff" << std::endl;
		else
		{
			fnum = static_cast<float>(ldnum);
			if (std::fmod(ldnum, 1.0) != 0.0)
				std::cout << "float : " << fnum << "f" << std::endl;
			else
				std::cout << "float : " << fnum << ".0f" << std::endl;
				
		}

		//convert to double

		if (num.compare("+inf") == 0)
			std::cout << "double : +inf" << std::endl;
		else if (num.compare("-inf") == 0)
			std::cout << "double : -inf" << std::endl;
		else if (num.compare("nan") == 0)
			std::cout << "double : nan" << std::endl;
		else if ((num.length() == 1 && std::isprint(c) && (c > 57 || c < 48)) || !number)
			std::cout << "double : Impossible" << std::endl;
		else if (ldnum >= std::numeric_limits<double>::infinity())
			std::cout << "double :: +inf" << std::endl;
		else if (ldnum <= -std::numeric_limits<double>::infinity())
			std::cout << "double :: -inf" << std::endl;
		else
		{
			dnum = static_cast<double>(ldnum);
			if (std::fmod(ldnum, 1.0) != 0.0)
				std::cout << "double : " << dnum << std::endl;
			else
				std::cout << "double : " << dnum << ".0" << std::endl;
		}
	}
}