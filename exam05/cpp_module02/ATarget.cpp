/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:04:04 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:44:30 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ATarget::ATarget() {
};

ATarget::ATarget(const std::string &newType) : type(newType) {
}

ATarget::ATarget(const ATarget &src) {
	*this = src;
}

ATarget::~ATarget() {
};

ATarget&	ATarget::operator=(const ATarget &src) {
	if (this != &src) {
		this->type = src.type;
	}
	return (*this);
}

const std::string&	ATarget::getType() const {
	return (type);
}

void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!\n";
}
