
#include "PolynomialList.h"
#include <iostream>

int main()
{
    cout << "Polynomial Calculator\n";

    // Variables used for first and second polynominal, and the final result and user choice
    Polynominal poly_1, poly_2, result;
    char choice;
    // Displays the menu for user to navigate through
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Enter First Polynomial\n";
        cout << "2. Enter Second Polynomial\n";
        cout << "3. Add Polynomials\n";
        cout << "4. Show Result\n";
        cout << "5. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        if (choice == '1') {
            poly_1 = inputPolynomial();
            cout << "First Polynomial entered: "; 
            poly_1.displayResult();
        }
        else if (choice == '2') {
            poly_2 = inputPolynomial();
            cout << "Second Polynomial Entered: ";
            poly_2.displayResult();
        }
        else if (choice == '3') {
            if (poly_1.isEmpty() || poly_2.isEmpty()) {
                cout << "Please enter both polynomials first.\n";
            }
            else {
                result = poly_1.addPolynomials(poly_2);
                cout << "Polynomials added.\n";
            }
        }
        else if (choice == '4') {
            if (result.isEmpty()) {
                cout << "No result to show. Please add polynomials first.\n";
            }
            else {
                cout << "Result: ";
                result.displayResult();

            }
        }
    }
}

