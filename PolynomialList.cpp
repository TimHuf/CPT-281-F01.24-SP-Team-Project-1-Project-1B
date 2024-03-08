#include "PolynomialList.h"

#include <iostream>
#include <sstream>



// Constructor that initializes an empty polynomial.
PolynomialList::PolynomialList() {}

void PolynomialList::inputPolynomial() {
	// Prompt user to enter a polynomial.
	string input;
	cout << "Enter a polynomial: ";
	getline(cin, input);

	// Use a string stream to break up the polynomial into terms.
	istringstream iss(input);
	string termString;

	while (getline(iss, termString, '+')) {
		// Parse each term add add it to the polynomial.
		istringstream termStream(termString);
		int coefficient, exponent;
		termStream >> coefficient >> exponent;
		polynomial.push_back(Term(coefficient, exponent));
	}

	// After parsing all the terms, sort and combine like terms.
	sortAndCombineLikeTerms();
}


void PolynomialList::sortAndCombineLikeTerms() {
	// Sort the polynomial in decreasing order of exponents.
	polynomial.sort(std::greater<Term>());

	auto it = polynomial.begin();

	// Iterate through the polynomial to combine like terms.
	while (it != polynomial.end()) {
		auto current = it;
		auto next = std::next(it);
		if (next != polynomial.end() && *current == *next) {
			// Combine like terms.
			current->setCoefficient(current->getCoefficient() + next->getCoefficient());
			it = polynomial.erase(next);
		}
		else {
			++it;
		}
	}
}


// Function that adds the two polynomials.
// Takes another PolynomialList as an argument and returns a new PolynomialList containing the sum of the two polynomials.
PolynomialList PolynomialList::addPolynomials(const PolynomialList& other) const {
	 PolynomialList result;	// Result polynomial initialized as an empty polynomial.

	// Iterators for the two polynomials, both initialized to the beginning of each polynomial.
	auto iterator1 = polynomial.begin();
	auto iterator2 = other.polynomial.begin();

	// Iterate through the terms of the two polynomials.
	while (iterator1 != polynomial.end() && iterator2 != other.polynomial.end()) {
		// If the exponents of the current terms are equal...
		if (iterator1->getExponent()  == iterator2->getExponent()) {
			// Then add their coefficients together.
			result.polynomial.push_back(Term(iterator1->getCoefficient() + iterator2->getCoefficient(), iterator1->getExponent()));
			iterator1++;
			iterator2++;
		}
		else if (iterator1->getExponent() < iterator2->getExponent()) {
			// Term in first polynomial has smaller exponent
			result.polynomial.push_back(*iterator2);
			iterator2++;
		}
		else {
			// Term in second polynomial has smaller exponent
			result.polynomial.push_back(*iterator1);
			iterator1++;
		}
	}

	// Copy remaining terms from first polynomial.
	while (iterator1 != polynomial.end()) {
		result.polynomial.push_back(*iterator1);
		iterator1++;
	}

	// Copy remaining terms from second polynomial.
	while (iterator2 != other.polynomial.end()) {
		result.polynomial.push_back(*iterator2);
		iterator2++;
	}

	return result;
}

bool PolynomialList::isEmpty() const {
    return inputPolynomial = nullptr;
}

void PolynomialList::displayResult() const {
	auto it = polynomial.begin();
	it->display();

	// Iterate through the rest of the terms.
	for (++it; it != polynomial.end(); ++it) {
		if (it->getCoefficient() > 0) {
			cout << " + ";
		} 
		else {
			cout << " - ";
		}
		it->display();
	}

	cout << endl;
}
