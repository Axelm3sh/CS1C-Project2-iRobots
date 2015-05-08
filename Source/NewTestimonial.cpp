#include "Input.h"

TestimonialNode NewTestimonial()
{
	TestimonialNode newNode;
	int selection;

	cout << "\nPlease Enter Your Institution's Name: \n";
	getline(cin, newNode.user);

	cout << "\nPlease Enter Model of Robot You Bought:\n";
	cout << "1. Silver\n";
	cout << "2. Gold\n";
	cout << "3. Platinum\n";

	// Use Get and Check Input Function Here
	cin >> selection;

	cin.ignore(10, '\n');

	newNode.model = (selection == 3 ? "Platinum" : (selection == 2 ? "Gold" : "Silver"));

	cout << "Please Enter your comments on this robot: \n";
	getline(cin, newNode.text);

	cout << "Thank you for providing your feedback for our product.";

	return newNode;

}
