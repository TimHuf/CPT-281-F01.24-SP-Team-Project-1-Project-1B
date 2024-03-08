
#include "polynominal.h"
#include <iostream>

int main()
{
    cout << "Polynominal Calcultor\n";

    // Variables used for first and second polynominal, and the final result and user choice
    Polynominal poly_1, poly_2, result;
    char choice;
    // Displays the menu for user to navigate through
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Enter First Polynominal\n";
        cout << "2. Enter Second Polynominal\n";
        cout << "3. Add Polynominals\n";
        cout << "4. Show Result\n";
        cout << "5. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        if (choice == '1') {
            poly_1 = input_polynominal();
            cout << "First Polynominal entered: " << poly_1 << "\n";
        }
        else if (choice == '2') {
            poly_2 = input_polynominal();
            cout << "Second Polynominal Entered: " << poly_2 << "\n";
        }
        else if (choice == '3') {
            if (poly_1.head == nullptr || poly_2.head == nullptr) {
                cout << "Please enter btoh polynominals first.\n";
            }
            else {
                result = poly_1 + poly_2;
                cout << "Polynominals added.\n";
            }
        }
        else if (choice == '4') {
            if (result.head == nullptr) {
                cout << "No result to show. Please add polynominals first.\n";
            }
            else {
                cout << "Result: " << result << "\n";

            }
        }
    }
}

