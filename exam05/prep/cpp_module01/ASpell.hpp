/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:19 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 16:36:24 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ATarget;

class	ASpell {

public:
	ASpell();
	ASpell(const ASpell &src);
	ASpell(const std::string &newName, const std::string &newEffects);
	virtual ~ASpell();

	ASpell&	operator=(const ASpell &src);

	const std::string&	getName() const;
	const std::string&	getEffects() const;

	virtual ASpell*	clone() const = 0;

	void	launch(const ATarget &tgt) const;

protected:
	std::string	name;
	std::string	effects;
};
