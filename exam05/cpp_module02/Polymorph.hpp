/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:02:29 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 15:02:55 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class	Polymorph : public ASpell {

public:
	Polymorph(); // ocf constructor
	~Polymorph(); // ocf destructor

	ASpell*	clone() const;
};
