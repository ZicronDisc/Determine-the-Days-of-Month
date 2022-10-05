#include <iostream>
#include <string>
using namespace std;

void days(int month, int year) {
	string monthsInWords[13]{
		"", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December",
	};

	string* address;
	address = monthsInWords;

	int monthsWith31[7]{
		1, 3, 5, 7, 8, 10, 12
	};

	if (month == 2) {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			cout << *(address + month) << " " << year << " has 29 days.";
		}
		else {
			cout << *(address + month) << " " << year << " has 28 days.";
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (month == monthsWith31[i]) {
				cout << *(address + month) << " " << year << " has 31 days.";
				break;
			}
			else {
				cout << *(address + month) << " " << year << " has 30 days.";
				break;
			}
		}
	}
}

struct calendar{
	int monthInput;
	int yearInput;
};

int main() {

	struct calendar input;

	try {
		cout << "Enter the month from 1-12" << endl;
		cin >> input.monthInput;;

		if (input.monthInput <= 12 && input.monthInput >= 1) {
			cout << "Enter the year" << endl;
			cin >> input.yearInput;

			days(input.monthInput, input.yearInput);
		}
		else {
			throw(input.monthInput);
		}
	}
	catch (int monthInput) {
		cout << monthInput << " is an invalid month number";
	};	

	return 0;
}
