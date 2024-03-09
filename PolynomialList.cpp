#include "PolynomialList.h"

#include <iostream>
#include <sstream>

// Input a polynomial from the user. User enters polynomial in string format.
// Then this function parses into individual terms.
void PolynomialList::inputPolynomial() {
	// Prompt user to enter a polynomial.
	string input;
	cout << "Enter a polynomial: ";
	getline(cin, input);		// Read the entire line as a polynomial string.
	cout << "Entered polynomial: " << input << endl;

	// Modify the input string to simplify the parsing of the terms.
	size_t pos = 0;
	// This loop inserts a '+' before every '-' that is not at the beginning of the string.
	// This will help in splitting the string into terms at '+' characters later.
	while ((pos = input.find_first_of('-', pos)) != string::npos) {
		if (pos != 0) {
			// Insert a '+' before the '-' if '-' is not at the start of the string.
			// This is needed because the '-' sign indicates a negative coefficient,
			// but for splitting purposes, we want to treat it like a separate term.
			input.insert(pos, "+");
			pos++;	// Increment position to skip the newly inserted '+'.
		}
		pos++;	// Move to the next character in the string.
	}

	// Parse and add each term to the polynomial list.
	istringstream iss(input);
	string termString;
	while (getline(iss, termString, '+')) {
		Term t = Term::parseTerm(termString);
		if (t.getCoefficient() != 0) {
			polynomial.push_back(t);
		}
	}

	// Sort the terms and combine like terms.
	sortAndCombineLikeTerms();
}


// Sort the polynomial's terms in decreasing order of exponents and combine like terms.
void PolynomialList::sortAndCombineLikeTerms() {
	// Sort the polynomial in decreasing order of exponents.
	polynomial.sort();

	// Iterate through the list and combine terms with the same exponent.
	for (auto it = polynomial.begin(); it != polynomial.end();) {
		auto next = std::next(it);
		if (next != polynomial.end() && *it == *next) {
			it->setCoefficient(it->getCoefficient() + next->getCoefficient());
			polynomial.erase(next);	// Remove the next term after combining.
		}
		else {
			++it;
		}
	}
}


// Function that adds the two polynomials.
// other: the other polynomial to add to this one.
// Returns: a PolynomialList that is the sum of this polynomil and "other".
PolynomialList PolynomialList::addPolynomials(const PolynomialList& other) const {
	 PolynomialList result;	// Result polynomial initialized as an empty polynomial.

	// Iterators to traverse two polynomials, both initialized to the beginning of each polynomial.
	auto iterator1 = polynomial.begin();
	auto iterator2 = other.polynomial.begin();

	// Iterate through both polynomials and add terms.
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

	// Sort and combine like terms in the result.
	result.sortAndCombineLikeTerms();
	return result;
}

// Check if the polynomial list is empty.
bool PolynomialList::isEmpty() const {
    return polynomial.empty();
}

// Display the polynomial in a user-friendly fashion.
void PolynomialList::displayResult() const {
    if (polynomial.empty()) {
        cout << "0" << endl;	// Handle the case of an empty polynomial.
        return;
    }
    // Iterate over each term in the polynomial and display it.	
    bool isFirstTerm = true;
    for (const auto& term : polynomial) {
        if (!isFirstTerm) {
            cout << (term.getCoefficient() >= 0 ? " + " : " - ");
        } else if (term.getCoefficient() < 0) {
            cout << "-"; // Display a negative sign for the first term if negative.
        }
        term.display(isFirstTerm);
        isFirstTerm = false;
    }
    cout << endl;
}
