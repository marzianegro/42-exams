/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:02:40 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:52:37 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class	SpellBook {

public:
	SpellBook(); // ocf constructor
	~SpellBook(); // ocf destructor

	void	learnSpell(ASpell* spell);
	void	forgetSpell(const std::string &spell);
	ASpell*	createSpell(const std::string &spell);

private:
	SpellBook(const SpellBook &src); // ocf copy constructor

	SpellBook&	operator=(const SpellBook &src); // ocf copy assignment operator

	std::map<std::string, ASpell*>	spellBook;
};
