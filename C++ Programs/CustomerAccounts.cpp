/*	Daniel Brooks
	© 2017-10-23
	Chapter 11 Assignment

	CustomerAccounts.cpp
	Description:	This program creates an array of 10 Account structures
				and gives the user a menu-driven interface to: 1) enter
				data into the array; 2) change the contents of any
				element; or 3) display all the data in the array.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure definition
struct Account {
	string name,
		   address,
		   city,
		   state,
		   zip,
		   telephone,
		   lastPayment;
	double balance;
};

// Function prototypes
void displayMenu();
void createAccount(Account [], short);
void displayAccounts(Account [], short);
void searchAccounts(Account [], short);

int main() {
	// Create Account array
	const short ARRAY_SIZE = 10;
	Account acctArray[ARRAY_SIZE];
	short lastAcct = 0;	// Number of accounts in the array

	// Variables for user input.
	short choice = 0;
	short acctToEdit = 0;

	// Until user quits, display menu.
	while (choice != 5) {
		displayMenu();

		// Get & validate user choice.
		cin >> choice;
		cout << endl;
		switch (choice) {
			// Option 1: Enter data into the array:
			// 	• Get and validate user input.
			case 1:	if (lastAcct == ARRAY_SIZE) {
						cout << "Can't create any more accounts.\n";
						break;
					}
					cin.ignore();
					createAccount(acctArray, lastAcct);
					lastAcct++;
					break;
			// Option 2: Change the contents of any element:
			// 	• Ask user which element to change.
			// 	• Get and validate user input.
			case 2: if (lastAcct == 0) {
						cout << "There are no accounts to edit.\n";
						break;
					}
					else if (lastAcct == 1) {
						acctToEdit = 0;
					}
					else {
						cout << "Which account would you like to edit "
							 << "(1 thru " << lastAcct << ")? ";
						cin  >> acctToEdit;
						acctToEdit--;
					}
					cin.ignore();
					createAccount(acctArray, acctToEdit);
					break;
			// Option 3: Display all the data in the array:
			// 	• Output the array using a for loop.
			case 3: if (lastAcct == 0) {
						cout << "There are no accounts to display.\n";
						break;
					};
					displayAccounts(acctArray, lastAcct);
					break;
			// Option 4: Search for an account.
			case 4: cin.ignore();
					searchAccounts(acctArray, ARRAY_SIZE);
					break;
			// Option 5: Quit the program.
			case 5: break;
			default:	cin.ignore();
					cout << "That is not a valid choice. "
						 << "Please choose again.\n";
		};
	};
	cout << "Now exiting the program.\n";

	return 0;
}
/*
 * displayMenu definition:
 * This function displays a menu to the user.
 */
void displayMenu() {
	// Display a menu.
	cout << "\n========= Menu =========\n"
		 << "1) Create an account\n"
		 << "2) Edit an account\n"
		 << "3) Display all accounts\n"
		 << "4) Search for an account\n"
		 << "5) Exit the program\n"
		 << "========================\n"
		 << "Enter your choice: ";
}
/*
 * createAccount definition:
 * This function creates or replaces an Account element in
 * the array (first parameter) at the index specified by the
 * second parameter.
 * Data must be entered for all fields, and account
 * balances cannot be entered as a negative number.
 */
void createAccount(Account accountArray[], short index) {
	cout << "Enter the information for account #" << (index + 1)
		 << ":\n\tName: ";
	getline(cin, accountArray[index].name);
	while (accountArray[index].name.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tName: ";
		getline(cin, accountArray[index].name);
	}
	cout << "\tStreet Address: ";
	getline(cin, accountArray[index].address);
	while (accountArray[index].address.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tStreet Address: ";
		getline(cin, accountArray[index].address);
	}
	cout << "\tCity: ";
	getline(cin, accountArray[index].city);
	while (accountArray[index].city.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tCity: ";
		getline(cin, accountArray[index].city);
	}
	cout << "\tState: ";
	getline(cin, accountArray[index].state);
	while (accountArray[index].state.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tState: ";
		getline(cin, accountArray[index].state);
	}
	cout << "\tZIP Code: ";
	getline(cin, accountArray[index].zip);
	while (accountArray[index].zip.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tZIP Code: ";
		getline(cin, accountArray[index].zip);
	}
	cout << "\tTelephone: ";
	getline(cin, accountArray[index].telephone);
	while (accountArray[index].telephone.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tTelephone: ";
		getline(cin, accountArray[index].telephone);
	}
	cout << "\tAccount Balance: ";
	cin  >> accountArray[index].balance;
	while (accountArray[index].balance < 0) {
		cout << "ERROR: Balance cannot be negative.\n"
			 << "\tAccount Balance: ";
		cin  >> accountArray[index].balance;
	}
	cin.ignore();
	cout << "\tDate of Last Payment: ";
	getline(cin, accountArray[index].lastPayment);
	while (accountArray[index].lastPayment.empty()) {
		cout << "ERROR: All fields must contain data.\n"
			 << "\tDate of Last Payment: ";
		getline(cin, accountArray[index].lastPayment);
	}
}
/*
 * displayAccounts definition:
 * This function displays all of the Account elements in
 * the array (first parameter). The second parameter is
 * the number of elements in the array.
 */
void displayAccounts(Account accountArray[], short elements) {
	cout << "Here are the current accounts:\n";
	for (int i = 0; i < elements; i++) {
		cout << "Account #" << (i + 1) << ":\n"
			 << "\t" << accountArray[i].name
			 << "\n\t" << accountArray[i].address
			 << "\n\t" << accountArray[i].city << ", "
			 << accountArray[i].state << " "
			 << accountArray[i].zip
			 << "\n\tTelephone: " << accountArray[i].telephone
			 << fixed << showpoint << setprecision(2)
			 << "\n\tAccount Balance: $"
			 << accountArray[i].balance
			 << "\n\tDate of Last Payment: "
			 << accountArray[i].lastPayment << endl;
	}
}
/*
 * searchAccounts definition:
 * This function searches an Account array for a customer account
 * using part of the customer's name as an argument. All accounts
 * that match should be displayed. If no account matches, a message
 * saying so should be displayed.
 */
void searchAccounts(Account accountArray[], short size) {
	cout << "Enter part of the customer's name as "
		 << "a search string: ";
	string searchString;
	bool found = false;
	getline(cin, searchString);
	for (int i = 0; i < size; i++) {
		if (accountArray[i].name.find(searchString) != std::string::npos) {
			cout << "Account #" << (i + 1) << ":\n"
				 << "\t" << accountArray[i].name
				 << "\n\t" << accountArray[i].address
				 << "\n\t" << accountArray[i].city << ", "
				 << accountArray[i].state << " "
				 << accountArray[i].zip
				 << "\n\tTelephone: " << accountArray[i].telephone
				 << fixed << showpoint << setprecision(2)
				 << "\n\tAccount Balance: $"
				 << accountArray[i].balance
				 << "\n\tDate of Last Payment: "
				 << accountArray[i].lastPayment << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "There are no account names that match your search.\n";
	}
}
