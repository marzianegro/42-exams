/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:54:50 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:50:25 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() {
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

Warlock::Warlock(const std::string &newName, const std::string &newTitle) : name(newName), title(newTitle) {
	std::cout << name << ": This looks like another boring day.\n";
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
	std::cout << name << ": I am " << name << ", " << title <<"!\n";
}

void	Warlock::learnSpell(ASpell *spell) {
	spellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(const std::string &spell) {
	spellBook.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string &spell, const ATarget &tgt) {
	ASpell	*tmp = 	spellBook.createSpell(spell);

	if (tmp) {
		tmp->launch(tgt);
	}
}
