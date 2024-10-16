/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:32:15 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:36:27 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ASpell;

class	ATarget {

public:
	ATarget(); // ocf constructor
	ATarget(const std::string &newType);
	ATarget(const ATarget &src); // ocf copy constructor
	virtual ~ATarget(); // ocf destructor

	ATarget&	operator=(const ATarget &src); // ocf copy assignment operator

	const std::string&	getType() const;

	virtual ATarget*	clone() const = 0;

	void	getHitBySpell(const ASpell &spell) const;

protected:
	std::string	type;
};
