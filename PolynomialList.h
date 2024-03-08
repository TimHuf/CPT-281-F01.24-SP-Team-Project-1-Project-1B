#ifndef POLYNOMIALLIST_H
#define POLYNOMIALLIST_H

#include <list>
#include "Term.h"


class PolynomialList {
public:
	// Constructor
	PolynomialList() = default;

	// Class-member functions.
	// Function to input a polynomial.
	void inputPolynomial();

	// Function to add two polynomials and return the result.
	PolynomialList addPolynomials(const PolynomialList& other) const;

	// Function to display the result polynomial.
	void displayResult() const;

	// Function to check if poolynomial is empty.
	bool isEmpty() const;


private:
	std::list<Term> polynomial;

	// Sort and combine like terms in the polynomial.
	void sortAndCombineLikeTerms();
};

#endif


