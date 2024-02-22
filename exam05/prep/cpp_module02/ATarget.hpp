/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:08 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:19:04 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ASpell;

class	ATarget {

public:
	ATarget();
	ATarget(const ATarget &src);
	ATarget(const std::string &newType);
	virtual ~ATarget();

	ATarget&	operator=(const ATarget &src);

	const std::string&	getType() const;

	virtual ATarget*	clone() const = 0;

	void	getHitBySpell(const ASpell &spell) const;

protected:
	std::string	type;
};
