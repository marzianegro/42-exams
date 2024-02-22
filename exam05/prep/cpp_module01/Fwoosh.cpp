/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:19:37 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:50:27 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	name = "Fwoosh";
	effects = "fwooshed";
}

Fwoosh::~Fwoosh() {
}

ASpell*	Fwoosh::clone() const {
	return (new Fwoosh());
}
