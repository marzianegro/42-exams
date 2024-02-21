/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:04:04 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:29:06 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ATarget::getHitBySpell(const ASpell &obj) const {
	std::cout << type << " has been " << obj.getEffects() << "!\n";
}
