/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:10:20 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 12:58:27 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	this->name = "Fwoosh";
	this->effects = "fwooshed";
};

Fwoosh::~Fwoosh() {
}

ASpell*	Fwoosh::clone() const {
	return (new Fwoosh());
}
