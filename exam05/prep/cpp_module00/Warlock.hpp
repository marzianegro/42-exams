/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:55:03 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 16:03:32 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Warlock {

public:
	Warlock(const std::string &newName, const std::string &newTitle);
	~Warlock();

	const std::string&	getName(void) const;
	const std::string&	getTitle(void) const;

	void	setTitle(const std::string &newTitle);

	void	introduce() const;

private:
	Warlock();
	Warlock(const Warlock &src);

	Warlock&	operator=(const Warlock &src);

	std::string	name;
	std::string	title;
};
