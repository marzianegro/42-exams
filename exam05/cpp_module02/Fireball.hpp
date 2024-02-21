/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:01:22 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:01:42 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class	Fireball : public ASpell {

public:
	Fireball(); // ocf constructor
	~Fireball(); // ocf destructor

	ASpell*	clone() const;
};
