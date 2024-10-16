/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:07:25 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:13:17 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {
}

SpellBook::SpellBook(const SpellBook &src) {
	*this = src;
}

SpellBook::~SpellBook() {
}

SpellBook&	SpellBook::operator=(const SpellBook &src) {
	if (this != &src) {
	}
	return (*this);
}

void	SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		spellBook[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(const std::string &spell) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spell);

	if (it != spellBook.end()) {
		spellBook.erase(it);
	}
}

ASpell*	SpellBook::createSpell(const std::string &spell) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spell);

	if (it != spellBook.end()) {
		return (spellBook[spell]);
	}
	return (NULL);
}
