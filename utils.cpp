/*
 * utils.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: Kareem Ergawy
 */
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;

/**
 * Rounds a double number n to x decimal places
 * For example, roundToXDecimalPlaces(13.258487, 2) returns 13.26
 */
double roundToXDecimalPlaces(double n, int x) {
	double power = pow(10.0, x);
	return ceil((n * power) - 0.5) / power;
}

/**
 * Returns the reverse of the provided c-string.
 * For example, reverseString("star") returns "rats"
 */
char* reverseString(char string[]) {
	int length = 0;
	while (string[length++] != '\0')
		;
	length--;
	char* revStr = new char[length];
	for (int i = length - 1; i >= 0; i--) {
		revStr[length - i - 1] = string[i];
	}

	revStr[length] = '\0';
	return revStr;
}

/**
 * Converts an integer number n to its corresponding char array using the provided base
 * The default base is 10
 * For example, convertIntToCharArray(31, 16) returns "1F"
 */
char* convertIntToCharArray(int n, int base = 10) {

	char* charArray = new char[255];

	if (n == 0) {
		strcpy(charArray, "0");
		return charArray;
	}

	int index = 0;

	while (n > 0) {
		int modResult = n % base;
		if (modResult < 10) {
			charArray[index++] = '0' + modResult;
		} else {
			charArray[index++] = 'A' + (modResult - 10);
		}
		n = n / base;
	}

	charArray[index] = '\0';
	charArray = reverseString(charArray);
	return charArray;
}

/**
 * Computes the reduced structure for some string.
 * Very useful in problems that involve comparison between string based on their structure.
 * Structure mean the repeated characters and their relevant positions.
 * For example, seem and keen have same structure which is abbc.
 */
string computeStrcture(string word) {
	char strct[26];
	for (int i = 0; i < 26; i++) {
		strct[i] = '*';
	}

	char current = 'a';
	string structure;
	for (unsigned int i = 0; i < word.length(); i++) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			if (strct[word[i] - 'a'] == '*') {
				strct[word[i] - 'a'] = current;
				current++;
			}
			structure = structure + strct[word[i] - 'a'];
		} else {
			structure = structure + word[i];
		}
	}

	return structure;
}

bool isPrime(int n) {

	for (int i = 2; i < sqrt(n); i++) {
		if ((n % i) == 0) {
			return false;
		}
	}

	return true;
}

typedef unsigned long ULONG;

ULONG modExp(ULONG a, ULONG pow, ULONG base) {
	if (pow == 0) {
		return 1;
	}

	if (pow == 1) {
		return a % base;
	}

	ULONG tmp = modExp(a, pow / 2, base);
	tmp = (tmp * tmp) % base;
	return (tmp * modExp(a, pow % 2, base)) % base;
}

long gcd(long n, long m) {
	if (n < m) {
		long tmp = n;
		n = m;
		m = tmp;
	}

	if (n % m == 0) {
		return m;
	}

	return gcd(m, n % m);
}

int main() {

	cout << int('1' - '*') << endl;
	cout << int('J' - 'C');

	return 0;
}
