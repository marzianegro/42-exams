/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:01:49 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:02:15 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball() {
	this->name = "Fireball";
	this->effects = "burnt to a crisp";
};

Fireball::~Fireball() {
}

ASpell*	Fireball::clone() const {
	return (new Fireball());
}
