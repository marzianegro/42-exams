/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:28:18 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:33:05 by mnegro           ###   ########.fr       */
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
		targetType[tgt->getType()] = tgt->clone();
	}
}

void		TargetGenerator::forgetTargetType(const std::string &tgt) {
	std::map<std::string, ATarget*>::iterator it = targetType.find(tgt);

	if (it != targetType.end()) {
		targetType.erase(it);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string &tgt) {
	std::map<std::string, ATarget*>::iterator it = targetType.find(tgt);

	if (it != targetType.end()) {
		return (targetType[tgt]);
	}
	return (NULL);
}
