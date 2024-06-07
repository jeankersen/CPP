/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:16 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/06 15:25:05 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string COLOR_ORANGE = "\033[38;5;208m";   // Orange
const std::string COLOR_BACK = "\033[0m";            // Black

int main() {
    try {
        Bureaucrat random;
        Bureaucrat bob("Bob", 2);
        Bureaucrat papa(bob);
        std::cout << bob << std::endl;
        std::cout << random << std::endl;
        std::cout << papa << std::endl;
        
        std::cout << std::endl;
        std::cout << COLOR_ORANGE <<  " TEST 1" << COLOR_BACK << std::endl;
        bob.addGrade();
        random.addGrade();
        std::cout << bob << std::endl;
        std::cout << random << std::endl;
        
        std::cout << std::endl;
        std::cout << COLOR_ORANGE <<  " TEST 2" << COLOR_BACK << std::endl;
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        alice.takeGrade();
        std::cout << alice << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        std::cout << COLOR_ORANGE <<  " TEST 3" << COLOR_BACK << std::endl;
        Bureaucrat high("High", 0); // Devrait jeter une exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        std::cout << COLOR_ORANGE <<  " TEST 4" << COLOR_BACK << std::endl;
        Bureaucrat low("Low", 151); // Devrait jeter une exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}