/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:44:55 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:26:59 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() {
	this->type = "Incospicuous Red-brick Wall";
}

BrickWall::~BrickWall() {
}

ATarget*	BrickWall::clone() const {
	return (new BrickWall());
}
