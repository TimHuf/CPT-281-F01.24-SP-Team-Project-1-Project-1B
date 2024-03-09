#include "Term.h"

using namespace std;
#include <iostream>
#include <sstream>


// Constructor for the Term class.
// Initializes a 'Term' object with the given coefficient and exponent.
Term::Term(int coefficient, int exponent) : coefficient(coefficient), exponent(exponent) {}


// Function to parse a term from a polynomial string and extract the coefficient and exponent.
// termString: a string representing a term in the polynomial.
// Returns: a Term object constructed from the parsed coefficient and exponent.
Term Term::parseTerm(const string& termString) {
	int coefficient = 0;
	int exponent = 0;
	bool negative = false;
	size_t i = 0;

	// Check for negative coefficient and handle.
	if (termString[i] == '-') {
	    negative = true;
	    i++;
	}
	
	// Parse the coefficient part of the term.
	while (i < termString.size() && isdigit(termString[i])) {
	    coefficient = coefficient * 10 + (termString[i] - '0');
	    i++;
	}
	// Handle the case where the coefficient is 1 or -1.
	// If there is no numerical coefficient.
	if (i == 0 || (i == 1 && negative)) {
	    coefficient = negative ? -1 : 1;
	} else if (negative) {
	    coefficient = -coefficient;
	}
	
	// Parse the exponent part of the term (where there is an x then ^).
	if (i < termString.size() && termString[i] == 'x') {
	    i++;    // Skip x.
	    exponent = 1;   // Default exponent.
	    if (i < termString.size() && termString[i] == '^') {
	        i++; // Skip '^'
	        exponent = 0; // Reset getExponent
	        while (i < termString.size() && isdigit(termString[i])) {
	            exponent = exponent * 10 + (termString[i] - '0');
	            i++;
	        }
	    }
	}
	
	return Term(coefficient, exponent);
}


// Getter for the coefficient.
int Term::getCoefficient() const {
	return coefficient;
}

// Getter for the exponent.
int Term::getExponent() const {
	return exponent;
}


// Setter for updating the coefficient.
void Term::setCoefficient(int newCoefficient) {
	coefficient = newCoefficient;
}


// Overload (less than) comparison operator to sort terms based on exponent.
bool Term::operator<(const Term& other) const {
	return exponent > other.exponent; // Sort in decreasing order
}

// Over equality operator for comparison based on exponent.
bool Term::operator==(const Term& other) const {
	return exponent == other.exponent;
}

// Display function to print the term in user-friendly fashion.
// isFirstTerm: indicates whether this term is the first in its polynomial.
// Also handles formatting of the coefficient and exponent, including when there is no coefficient (which means that its 1) and exponent.
void Term::display(bool isFirstTerm) const {
    int absCoeff = std::abs(coefficient); // Absolute value of coefficient.
    
    if (coefficient != 0) {
	// Display the coefficient, but NOT when the coefficient is 1.
        if (isFirstTerm || absCoeff != 1 || exponent == 0) {
            cout << absCoeff;
        }
        
        // Display 'x' and exponent.
	// Also takes care of instances when the exponent is 1 or 0.
        if (exponent != 0) {
            cout << "x";
            if (exponent != 1) {
                cout << "^" << exponent;
            }
        }
    }
}

