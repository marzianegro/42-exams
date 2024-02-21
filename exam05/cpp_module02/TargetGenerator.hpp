/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:59 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:46:36 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <map>

class	TargetGenerator {

public:
	TargetGenerator(); // ocf constructor
	~TargetGenerator(); // ocf destructor

	TargetGenerator&	operator=(const TargetGenerator &src); // ocf copy assignment operator

	void		learnTargetType(ATarget *tgt);
	void		forgetTargetType(const std::string &tgt);
	ATarget*	createTarget(const std::string &tgt);

private:
	TargetGenerator(const TargetGenerator &src); // ocf copy constructor

	std::map<std::string, ATarget*>	targetType;
};
