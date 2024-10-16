/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:19:37 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:28:56 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}

Fwoosh::~Fwoosh() {
}

ASpell*	Fwoosh::clone() const {
	return (new Fwoosh());
}
