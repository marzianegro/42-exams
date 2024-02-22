/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:57:26 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:05:26 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <map>

class	TargetGenerator {

public:
	TargetGenerator();
	~TargetGenerator();

	void		learnTargetType(ATarget *tgt);
	void		forgetTargetType(const std::string &tgt);
	ATarget*	createTarget(const std::string &tgt);

private:
	TargetGenerator(const TargetGenerator &src);

	TargetGenerator&	operator=(const TargetGenerator &src);

	std::map<std::string, ATarget*>	targetBook;
};
