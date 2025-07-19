/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/15 16:25:32 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);      // grade 50
        Form form1("Form A", 75, false, 25); // besoin d’un grade 75 pour signer

        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;

        // Bob peut signer car 50 <= 75
        form1.beSigned(bob);

        std::cout << "Form signed? " << (form1.getsigned() ? "Yes" : "No") << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing error case ---\n" << std::endl;

    try {
        Bureaucrat alice("Alice", 150);    // grade trop bas
        Form form2("Form B", 50, false, 25); // besoin d’un grade 50

        std::cout << alice << std::endl;
        std::cout << form2 << std::endl;

        // Alice ne peut pas signer car 150 > 50 → exception attendue
        form2.beSigned(alice);

        std::cout << "Form signed? " << (form2.getsigned() ? "Yes" : "No") << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


// int main() {
//     try {
//         Bureaucrat b("Alice", 30);
//         Form f("Form A", 50, 100);

//         std::cout << b.getName() << " with grade " << b.getGrade() << " tries to sign form\n";
//         f.beSigned(b);
//         std::cout << "Form signed successfully!\n";
//     }
//     catch (std::exception &e) {
//         std::cerr << "Exception: " << e.what() << "\n";
//     }
// }