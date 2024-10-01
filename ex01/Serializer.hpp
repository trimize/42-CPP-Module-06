/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:31:29 by to                #+#    #+#             */
/*   Updated: 2024/10/01 18:19:58 by trimize          ###   ########.fr       */
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
		virtual ~Serializer() = 0;
		Serializer	&operator=(Serializer const &s);
	public :
		static uintptr_t serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
		
};

#endif