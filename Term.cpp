#include "Term.h"

using namespace std;
#include <iostream>
#include <sstream>


// Constructor
// Initializes a 'Term' object with the given coefficient and exponent.
Term::Term(int coefficient, int exponent) : coefficient(coefficient), exponent(exponent) {}


// Function to parse the string representing a term in a polynomial and extracts the coefficient and exponent.
Term Term::parseTerm(const string& termString) {
	int coefficient = 0;
	int exponent = 0;
	bool negative = false;
	size_t i = 0;

	// Check for negative coefficient.
	if (termString[i] == '-') {
	    negative = true;
	    i++;
	}
	
	// Parse coefficient
	while (i < termString.size() && isdigit(termString[i])) {
	    coefficient = coefficient * 10 + (termString[i] - '0');
	    i++;
	}
	// Coefficient is 1 or -1.
	if (i == 0 || (i == 1 && negative)) {
	    coefficient = negative ? -1 : 1;
	} else if (negative) {
	    coefficient = -coefficient;
	}
	
	// Parse variable 'x' and exponent.
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


// Getter functions
int Term::getCoefficient() const {
	return coefficient;
}

int Term::getExponent() const {
	return exponent;
}


// Setter function
void Term::setCoefficient(int newCoefficient) {
	coefficient = newCoefficient;
}


// Overload comparison operators to sort terms.
bool Term::operator<(const Term& other) const {
	return exponent > other.exponent; // Sort in decreasing order
}

bool Term::operator==(const Term& other) const {
	return exponent == other.exponent;
}

// NEW DISPLAY function
void Term::display(bool isFirstTerm) const {
    int absCoeff = std::abs(coefficient); // Absolute value of coefficiient
    
    if (coefficient != 0) {
        if (isFirstTerm || absCoeff != 1 || exponent == 0) {
            cout << absCoeff;
        }
        
        // Display x and exponent if possible.
        if (exponent != 0) {
            cout << "x";
            if (exponent != 1) {
                cout << "^" << exponent;
            }
        }
    }
}

