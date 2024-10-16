/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:09:40 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:18:28 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "ASpell.hpp"

ASpell::ASpell() {
}

ASpell::ASpell(const ASpell &src) {
	*this = src;
}

ASpell::~ASpell() {
}

ASpell&	ASpell::operator=(const ASpell &src) {
	if (this != &src) {
		this->name = src.name;
		this->effects = src.effects;
	}
	return (*this);
}

ASpell::ASpell(const std::string &newName, const std::string &newEffects) : name(newName), effects(newEffects) {
}

const std::string&	ASpell::getName() const {
	return (name);
}

const std::string&	ASpell::getEffects() const {
	return (effects);
}

void	ASpell::launch(const ATarget &tgt) const {
	tgt.getHitBySpell(*this);
}

