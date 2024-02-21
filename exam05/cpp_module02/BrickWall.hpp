/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:03:49 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:29:37 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"

class	BrickWall : public ATarget {

public:
	BrickWall(); // ocf constructor
	~BrickWall(); // ocf destructor

	ATarget*	clone() const;
};
