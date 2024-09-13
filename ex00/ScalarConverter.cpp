/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: to <to@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:59:37 by to                #+#    #+#             */
/*   Updated: 2024/08/19 20:23:24 by to               ###   ########.fr       */
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
	std::stringstream snum;

	//convert to char

	snum << num;
	snum >> ldnum;
	if (num.empty())
	{
		std::cout<< "char : Impossible" << std::endl;
		std::cout << "int : Impossible" << std::endl;
		std::cout << "float : Impossible" << std::endl;
		std::cout << "double : Impossible" << std::endl;
	}
	else
	{
		if (((ldnum == 0 && num.compare("0") == 0)) || (0 < ldnum && ldnum <= 32) || (ldnum == 127) || (ldnum < 0))
			std::cout<< "char : Non displayable" << std::endl;
		else if ((ldnum > 127) || (!num.empty() && ldnum == 0 && num.compare("0") != 0))
			std::cout<< "char : Impossible" << std::endl;
		else
		{
			cnum = ldnum;
			std::cout << "char : " << "'" << cnum << "'" << std::endl;
		}

		//convert to int

		if (ldnum > 2147483647 || ldnum < -2147483648 || (!num.empty() && ldnum == 0 && num.compare("0") != 0))
			std::cout << "int : Impossible" << std::endl;
		else
		{
			inum = (int)ldnum;
			std::cout << "int : " << inum << std::endl;
		}

		//convert to float

		if ((!num.empty() && ldnum == 0 && num.compare("0") != 0 && num.compare("nan") != 0))
			std::cout << "float : Impossible" << std::endl;
		else if (num.compare("nan") == 0)
			std::cout << "float :: nanf" << std::endl;
		else if (ldnum >= std::numeric_limits<float>::infinity())
			std::cout << "float :: inff" << std::endl;
		else if (ldnum <= -std::numeric_limits<float>::infinity())
			std::cout << "float :: -inff" << std::endl;
		else
		{
			fnum = (float)ldnum;
			std::cout << "float : " << fnum << "f" << std::endl;
		}

		//convert to double

		if ((!num.empty() && ldnum == 0 && num.compare("0") != 0 && num.compare("nan") != 0))
			std::cout << "double : Impossible" << std::endl;
		else if (num.compare("nan") == 0)
			std::cout << "double : nan" << std::endl;
		else if (ldnum >= std::numeric_limits<double>::infinity())
			std::cout << "double :: inf" << std::endl;
		else if (ldnum <= -std::numeric_limits<double>::infinity())
			std::cout << "double :: -inf" << std::endl;
		else
		{
			dnum = (double)ldnum;
			std::cout << "double : " << dnum << std::endl;
		}
	}
}