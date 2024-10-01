/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:25:22 by to                #+#    #+#             */
/*   Updated: 2024/09/28 17:02:24 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *d = new Data();
	uintptr_t	raw;

	std::cout <<std::endl << "Data before serialization : " << d << std::endl << std::endl;
	
	raw = Serializer::serialize(d);

	std::cout << "Data after serialization : " << raw << std::endl << std::endl;

	d = Serializer::deserialize(raw);

	std::cout << "This should be equal to the first value : " << d << std::endl << std::endl;

	delete d;
}