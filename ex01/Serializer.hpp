/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:31:29 by to                #+#    #+#             */
/*   Updated: 2024/10/04 12:04:10 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private :
		Serializer();
		Serializer(Serializer &s);
		Serializer	&operator=(Serializer const &s);
	public :
		virtual ~Serializer() = 0;
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
		
};

#endif