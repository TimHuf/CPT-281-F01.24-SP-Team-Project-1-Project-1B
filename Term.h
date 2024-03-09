#ifndef TERM_H
#define TERM_H

#include <iostream>

// Term represents a single term of a polynomial with an int coefficient and exponent.
class Term {
private:
	// Data fields
	// Coefficient of the term.
	int coefficient;

	// Exponent of the term.
	int exponent;

public:
	// Constructor to intialize a Term with a given coefficient and exponent.
	Term(int coefficient, int exponent);


	// Static function to parse a term from a string inputted.
	// termString is expected to be "coefficientx^exponent.
	// Example - "3x^4" will be parsed as coefficient = 3 and exponent = 4.
	static Term parseTerm(const string& termString);

	// Getter functions.
	// Gets the term's coefficient.
	int getCoefficient() const;

	// Gets the term's exponent.
	int getExponent() const;

	// Setter function for updating the term's coefficient.
	void setCoefficient(int newCoefficient);

	// Overload the (less than) comparison operator for comparing terms based on their exponents.
	// This will be used when sorting the terms in decreasing order of their exponents.
	bool operator<(const Term& other) const;
	bool operator==(const Term& other) const;

	// Function to display the term.
	// isFirstTerm is used to control the display of the (+ or -) sign for the first term in the polynomial.
	void display(bool isFirstTerm = false) const;	
};

#endif
