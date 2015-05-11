#include "Input.h"
#include "MyHeader.h"



TestimonialNode NewTestimonial()
{

	TestimonialNode newNode;
	int selection;

	cout << "\nPlease Enter Your Institution's Name: (If you do not wish to leave a testimonial, leave this blank.\n";
	getline(cin, newNode.user);

	if(newNode.user != "")
	{
		selection = BoundaryCheck(robotType, 1, 3);

		// Use Get and Check Input Function Here

		newNode.model = (selection == 3 ? "Platinum" : (selection == 2 ? "Gold" : "Silver"));

		cout << "Please Enter your comments on this robot: \n";
		getline(cin, newNode.text);

		cout << "Thank you for providing your feedback for our product.";
	}

	return newNode;

}
