#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term {
private:
	// Data fields
	int coefficient;
	int exponent;

public:
	// Constructors
	Term(int coefficient, int exponent);


	// Function to extract the coefficient and exponent from the inputted polynomial.
	// Parses the string to extract.
	static Term parseTerm(const string& termString);

	// Getter functions
	int getCoefficient() const;
	int getExponent() const;

	// Setter functions
	void setCoefficient(int newCoefficient);

	// Overload comparison operators
	bool operator<(const Term& other) const;
	bool operator>(const Term& other) const;
	bool operator==(const Term& other) const;

	// Display term
	void display() const;
	
};

#endif
