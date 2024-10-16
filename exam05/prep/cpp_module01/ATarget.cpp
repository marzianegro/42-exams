/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:01 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 16:36:24 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget() {
}

ATarget::ATarget(const ATarget &src) {
	*this = src;
}

ATarget::~ATarget() {
}

ATarget&	ATarget::operator=(const ATarget &src) {
	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

ATarget::ATarget(const std::string &newType) : type(newType) {
}

const std::string&	ATarget::getType() const {
	return (type);
}

void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "\n";
}
