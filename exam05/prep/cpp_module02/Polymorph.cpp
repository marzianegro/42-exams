/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:44:26 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:28:38 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph() {
	this->name = "Polymorph";
	this->effects = "turned into a critter";
}

Polymorph::~Polymorph() {
}

ASpell*	Polymorph::clone() const {
	return (new Polymorph());
}
