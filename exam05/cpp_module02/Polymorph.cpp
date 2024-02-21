/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:03:10 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:03:28 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph() {
	this->name = "Polymorph";
	this->effects = "turned into a critter";
};

Polymorph::~Polymorph() {
}

ASpell*	Polymorph::clone() const {
	return (new Polymorph());
}
