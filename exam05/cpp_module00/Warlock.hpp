/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:40:33 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:18:41 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Warlock {

public:
	Warlock(const std::string &newName, const std::string &newTitle);
	~Warlock(); // ocf destructor

	const std::string&	getName() const;
	const std::string&	getTitle() const;

	void	setTitle(const std::string &newTitle);

	void	introduce() const;

private:
	Warlock(); // ocf constructor
	Warlock(const Warlock &src); // ocf copy constructor

	Warlock&	operator=(const Warlock &src); // ocf copy assignment operator
	
	std::string	name;
	std::string	title;

};
