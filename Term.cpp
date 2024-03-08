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

	istringstream iss(termString);


	// Extract coefficient from the string entered.
	iss >> coefficient;

	// Check for an 'x' or '^' to determine if there is an exponent.
	char x;
	if (iss >> x) {
		if (x == 'x') {
			// Check for '^' to get the exponent.
			char powerOf;
			if (iss >> powerOf >> exponent && powerOf == '^') {
				// Successfully extracted exponent.
			}
		}

		else {
			// If there is no 'x', the term is a constant.
			exponent = 0;

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

bool Term::operator>(const Term& other) const {
	return exponent < other.exponent; 
}

bool Term::operator==(const Term& other) const {
	return exponent == other.exponent;
}

// Display function
void Term::display() const {
	if (coefficient != 0) {
		if (exponent == 0) {
			cout << coefficient;
		}
		else {
			cout << coefficient << "x^" << exponent;
		}
	}
}
