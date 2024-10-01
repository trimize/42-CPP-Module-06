/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:50:31 by to                #+#    #+#             */
/*   Updated: 2024/09/28 17:04:37 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

Base	*generate(void)
{
	srand(time(NULL));

	int randNum = (rand() % 3) + 1;
	if (randNum == 1)
	{
		Base *a = new A();
		return (a);
	}
	else if (randNum == 2)
	{
		Base *b = new B();
		return (b);
	}
	else
	{
		Base *c = new C();
		return (c);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer is of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The pointer is of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The pointer is of type C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A	&a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "The pointer is of type A." << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "The pointer is of type B." << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "The pointer is of type C." << std::endl;
	}
	catch(const std::exception& e) {}
}

int	main()
{
	Base	*ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
}