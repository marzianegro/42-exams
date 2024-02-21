/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:17:12 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:52:38 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ATarget.hpp"

class	ATarget;

class	ASpell {

public:
	ASpell(); // ocf constructor
	ASpell(const std::string &newName, const std::string &newEffect);
	ASpell(const ASpell &src); // ocf copy constructor
	virtual ~ASpell(); // ocf destructor

	ASpell&	operator=(const ASpell &src); // ocf copy assignment operator

	const std::string&	getName() const;
	const std::string&	getEffects() const;

	virtual ASpell*	clone() const = 0;

	void	launch(const ATarget& obj) const;

protected:
	std::string	name;
	std::string	effects;
};
