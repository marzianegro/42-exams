/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:40:36 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 16:40:02 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() {
};

Warlock::Warlock(const std::string &newName, const std::string &newTitle) : name(newName), title(newTitle) {
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::Warlock(const Warlock &src) {
	*this = src;
}

Warlock::~Warlock() {
	std::cout << name << ": My job here is done!\n";
}

Warlock&	Warlock::operator=(const Warlock &src) {
	if (this != &src) {
		this->name = src.name;
		this->title = src.title;
	}
	return (*this);
}

const std::string&	Warlock::getName() const {
	return (name);
}
const std::string&	Warlock::getTitle() const {
	return (title);
}

void	Warlock::setTitle(const std::string &newTitle) {
	title = newTitle;
}

void	Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void	Warlock::learnSpell(ASpell *spell) {
	if (spell) {
		spellBook[spell->getName()] = spell;
	}
}

void	Warlock::forgetSpell(const std::string spell) {
	std::map<std::string, ASpell*>::iterator it;

	it = spellBook.find(spell);
	if (it != spellBook.end()) {
		spellBook.erase(it);
	}
}

void	Warlock::launchSpell(const std::string spell, const ATarget &tgt) {
	std::map<std::string, ASpell*>::iterator it;

	it = spellBook.find(spell);
	if (it != spellBook.end()) {
		it->second->launch(tgt);
	}
}
