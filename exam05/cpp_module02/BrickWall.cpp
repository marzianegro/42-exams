/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:04:02 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:04:23 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() {
	this->type = "Inconspicuous Red-brick Wall";
}

BrickWall::~BrickWall() {
}

ATarget*	BrickWall::clone() const {
	return (new BrickWall());
}
