/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:22:22 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:20:44 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() {
	type = "Target Practice Dummy";
}

Dummy::~Dummy() {
}

ATarget*	Dummy::clone() const {
	return (new Dummy());
}
