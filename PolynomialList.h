#ifndef POLYNOMIALLIST_H
#define POLYNOMIALLIST_H

#include <list>
#include "Term.h"


// PolynomialList class represents a polynomial as a list of Terms.
class PolynomialList {
public:
	// Default constructor. Initializes an empty polynomial list.
	PolynomialList() = default;

	// Class-member functions.
	// Function to input a polynomial from the user.
	// Reads a line of input and parses it into individual terms, which are then added to the polynomiallist.
	void inputPolynomial();

	// Function to add two polynomials and return the result as a new PolynomialList.
	// other: the PolynomialList to be added to this one.
	// Returns: a new PolynomialList representing the sum of first polynomial and "other".
	PolynomialList addPolynomials(const PolynomialList& other) const;

	// Function to display the result polynomial in a user-friendly fashion.
	// Fortmats and prints the polynomial terms to the console.
	void displayResult() const;

	// Function to check if polynomial is empty.
	// Returns: {true} is the polynomial list is empty, {false} otherwise.
	bool isEmpty() const;

private:
	// A doubly-linked list that stores the terms of the polynomial.
	std::list<Term> polynomial;

	// Sorts the polynomial terms in decreasing order of their exponents
	// and combines like terms (terms with the same exponent) in the polynomial.
	void sortAndCombineLikeTerms();
};

#endif
