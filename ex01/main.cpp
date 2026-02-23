/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:20:38 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 00:20:39 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Foo");

    if (!horde)
        return 1;

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;
    return 0;
}
