/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:16 by jvillefr          #+#    #+#             */
/*   Updated: 2024/06/03 10:30:21 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat random;
        Bureaucrat bob("Bob", 2);
        Bureaucrat papa(bob);
        std::cout << bob << std::endl;
        std::cout << random << std::endl;
        std::cout << papa << std::endl;
        
        bob.addGrade();
        random.addGrade();
        std::cout << bob << std::endl;
        std::cout << random << std::endl;

        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;
        alice.takeGrade();
        std::cout << alice << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat high("High", 0); // Devrait jeter une exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat low("Low", 151); // Devrait jeter une exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}