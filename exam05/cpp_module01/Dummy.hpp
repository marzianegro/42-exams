/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:13:55 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:25:40 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"

class	Dummy : public ATarget {

public:
	Dummy(); // ocf constructor
	~Dummy(); // ocf destructor

	ATarget*	clone() const;
};
