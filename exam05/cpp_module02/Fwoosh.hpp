/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:52:42 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 12:58:09 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class	Fwoosh : public ASpell {

public:
	Fwoosh(); // ocf constructor
	~Fwoosh(); // ocf destructor

	ASpell*	clone() const;
};
