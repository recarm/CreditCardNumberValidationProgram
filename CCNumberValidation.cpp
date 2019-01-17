#include <cmath>
#include <sstream> 
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>

// @about ; a program that checks if a credit card number is valid or not.

using namespace std;
bool isvalidcc(const string&);

bool isvalidcc(const string& num) {
			int total = 0; // the total gained by adding partA and partC
			int partA = 0; // total from partA
			int partB = 0; // total from partB
			int i = 0;

			for (i = num.length() - 2; i >= 0; i = i - 2) {
				int changedToInt = (num[i] - '0'); // changing each index of num into an int instead of char
				changedToInt = 2*changedToInt;
				if (changedToInt > 9) { // if the int is 10+, changing the digits to string and back to seperate ints and adds them up.
					string backToString = to_string(changedToInt);
					int number1 = (backToString[0] - '0');
					int number2 = (backToString[1] - '0');
					changedToInt = (number1 + number2);
				}
				partA = changedToInt + partA;
			}
			
			for (i = num.length() - 1; i>=0; i = i-2){
				int changedToInt = (num[i] - '0');
				partB = changedToInt + partB;
		}

		total = partA + partB; //sums the result

		if (total % 10 == 0) { //if total is divisible by 10
			return true;
		}
		else {
			return false;
		}
	
	// add all digits in the odd places from right to left

	// add both results from b and c

	// if divisible by 10, its valid, if not, invalid
	// must have 13 - 16 digits
	
}

int main()
{
	vector<string> cardnumbers = { // strings are put in a vector
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr; // vector is then iterated

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) { 
		cout << setw(2)  << i << " " 
			 << setw(17) << *itr 
			 << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}