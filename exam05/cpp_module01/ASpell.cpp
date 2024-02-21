/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:57:52 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 12:55:18 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {
};

ASpell::ASpell(const std::string &newName, const std::string &newEffect) : name(newName), effects(newEffect) {
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

const std::string&	ASpell::getName() const {
	return (name);
}

const std::string&	ASpell::getEffects() const {
	return (effects);
}

void	ASpell::launch(const ATarget &obj) const {
	obj.getHitBySpell(*this);
}
