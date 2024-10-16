/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:55:03 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:50:26 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>
#include <map>
#include "SpellBook.hpp"

class	Warlock {

public:
	Warlock(const std::string &newName, const std::string &newTitle);
	~Warlock();

	const std::string&	getName(void) const;
	const std::string&	getTitle(void) const;

	void	setTitle(const std::string &newTitle);

	void	introduce() const;

	void	learnSpell(ASpell *spell);
	void	forgetSpell(const std::string &spell);
	void	launchSpell(std::string &spell, const ATarget &tgt);

private:
	Warlock();
	Warlock(const Warlock &src);

	Warlock&	operator=(const Warlock &src);

	std::string	name;
	std::string	title;
	SpellBook	spellBook;
};
