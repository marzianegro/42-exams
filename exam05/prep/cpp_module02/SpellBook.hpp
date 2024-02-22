/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:46:07 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:18:30 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class	SpellBook {

public:
	SpellBook();
	~SpellBook();

	void	learnSpell(ASpell *spell);
	void	forgetSpell(const std::string &spell);
	ASpell*	createSpell(const std::string &spell);

private:
	SpellBook(const SpellBook &src);

	SpellBook&	operator=(const SpellBook &src);

	std::map<std::string, ASpell*>	spellBook;
};
