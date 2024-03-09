#include "PolynomialList.h"

#include <iostream>
#include <sstream>

void PolynomialList::inputPolynomial() {
	// Prompt user to enter a polynomial.
	string input;
	cout << "Enter a polynomial: ";
	getline(cin, input);
	cout << "Entered polynomial: " << input << endl;

	// NEW CODE ****************
	size_t pos = 0;
	while ((pos = input.find_first_of('-', pos)) != string::npos) {
		if (pos != 0) {
			input.insert(pos, "+");
			pos++;
		}
		pos++;	// move to next character
	}

	istringstream iss(input);
	string termString;
	while (getline(iss, termString, '+')) {
		Term t = Term::parseTerm(termString);
		if (t.getCoefficient() != 0) {
			polynomial.push_back(t);
		}
	}

	sortAndCombineLikeTerms();
}


// Sort the polynomial and combine like terms.
void PolynomialList::sortAndCombineLikeTerms() {
	// Sort the polynomial in decreasing order of exponents.
	polynomial.sort();

	for (auto it = polynomial.begin(); it != polynomial.end();) {
		auto next = std::next(it);
		if (next != polynomial.end() && *it == *next) {
			it->setCoefficient(it->getCoefficient() + next->getCoefficient());
			polynomial.erase(next);
		}
		else {
			++it;
		}
	}
}


// Function that adds the two polynomials. *** ERROR HERE ***
// Takes another PolynomialList as an argument and returns a new PolynomialList containing the sum of the two polynomials.
PolynomialList PolynomialList::addPolynomials(const PolynomialList& other) const {
	 PolynomialList result;	// Result polynomial initialized as an empty polynomial.

	// Iterators for the two polynomials, both initialized to the beginning of each polynomial.
	auto iterator1 = polynomial.begin();
	auto iterator2 = other.polynomial.begin();

	// Iterate through the terms of the two polynomials.
	while (iterator1 != polynomial.end() && iterator2 != other.polynomial.end()) {
		// If the exponents of the current terms are equal...
		if (iterator1->getExponent() == iterator2->getExponent()) {
			int newCoeff = iterator1->getCoefficient() + iterator2->getCoefficient();
			if (newCoeff != 0) {
				result.polynomial.push_back(Term(newCoeff, iterator1->getExponent()));
			}
			iterator1++;
			iterator2++;
		}
		else if (iterator1->getExponent() > iterator2->getExponent()) {
			result.polynomial.push_back(*iterator1);
			iterator1++;
		}
		else {
			result.polynomial.push_back(*iterator2);
			iterator2++;
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

	result.sortAndCombineLikeTerms();
	return result;
}



bool PolynomialList::isEmpty() const {
    return polynomial.empty();
}

// NEW DISPLAYRESULT Function
void PolynomialList::displayResult() const {
    if (polynomial.empty()) {
        cout << "0" << endl;
        return;
    }
    
    bool isFirstTerm = true;
    for (const auto& term : polynomial) {
        if (!isFirstTerm) {
            cout << (term.getCoefficient() >= 0 ? " + " : " - ");
        } else if (term.getCoefficient() < 0) {
            cout << "-"; //negative sign for the first term if negative.
        }
        term.display(isFirstTerm);
        isFirstTerm = false;
    }
    cout << endl;
}
