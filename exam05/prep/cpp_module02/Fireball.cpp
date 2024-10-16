/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:43:40 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:27:55 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball() {
	this->name = "Fireball";
	this->effects = "burnt to a crisp";
}

Fireball::~Fireball() {
}

ASpell*	Fireball::clone() const {
	return (new Fireball());
}
