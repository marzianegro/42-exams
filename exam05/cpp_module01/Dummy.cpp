/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:15:38 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 12:58:40 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() {
	this->type = "Target Practice Dummy";
}

Dummy::~Dummy() {
}

ATarget*	Dummy::clone() const {
	return (new Dummy());
}
