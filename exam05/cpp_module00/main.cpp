/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:10:48 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/21 16:15:00 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int	main(void)
{
	std::string lol;
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	if (jack->getName() == "Jack")
		std::cout << "getName is const" << std::endl;

	delete jack;
	return (0);
}
