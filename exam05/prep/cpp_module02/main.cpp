/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:28:31 by mnegro            #+#    #+#             */
/*   Updated: 2024/02/22 17:50:51 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "TargetGenerator.hpp"
#include "Warlock.hpp"
#include <iostream>

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  std::string popi = "Polymorph";
  std::string loli = "Fireball";
  richard.launchSpell(popi, *wall);
  richard.launchSpell(loli, *wall);
}
