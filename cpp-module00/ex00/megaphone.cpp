/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:19:47 by jvillefr          #+#    #+#             */
/*   Updated: 2024/03/29 16:19:48 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; argv[i][j]; j++)
                {
                    if(islower(argv[i][j]))
                        std::cout << (char)toupper(argv[i][j]);
                    else
                        std::cout << (char)argv[i][j];
                }
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND ENBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
