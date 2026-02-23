/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:53:56 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/23 23:53:57 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    std::cout << "----- Stack zombie -----" << std::endl;
    Zombie a("Stacky");
    a.announce();

    std::cout << "\n----- Heap zombie -----" << std::endl;
    Zombie *b = newZombie("Heapy");
    b->announce();
    delete b; 

    std::cout << "\n----- randomChump (stack inside function) -----" << std::endl;
    randomChump("Random");

    std::cout << "\nDone." << std::endl;
    return 0;
}
