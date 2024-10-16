/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:57:23 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:31:49 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}

TargetGenerator::TargetGenerator(const TargetGenerator &src) {
	*this = src;
}

TargetGenerator::~TargetGenerator() {
}

TargetGenerator&	TargetGenerator::operator=(const TargetGenerator &src) {
	if (this != &src) {
	}
	return (*this);
}

void		TargetGenerator::learnTargetType(ATarget *tgt) {
	if (tgt) {
		targetBook[tgt->getType()] = tgt->clone();
	}
}

void		TargetGenerator::forgetTargetType(const std::string &tgt) {
	std::map<std::string, ATarget*>::iterator	it = targetBook.find(tgt);

	if (it != targetBook.end()) {
		targetBook.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string &tgt) {
	std::map<std::string, ATarget*>::iterator	it = targetBook.find(tgt);

	if (it != targetBook.end()) {
		return (targetBook[tgt]);
	}
	return (NULL);
}
