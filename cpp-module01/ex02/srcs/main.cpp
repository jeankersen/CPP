/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:40:59 by jvillefr          #+#    #+#             */
/*   Updated: 2024/04/01 14:08:45 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<string.h>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "string adress: " << &str << std::endl;
    std::cout <<  "stringPTR adress: " << stringPTR << std::endl;
    std::cout <<  "stringREG Adress: " <<  &stringREF << std::endl;

    std::cout << "str value: " << str << std::endl;
    std::cout << "stringPTR value: " << *stringPTR << std::endl;
    std::cout << "stringREG value: " << stringREF << std::endl;
    
    
    return (0);
}