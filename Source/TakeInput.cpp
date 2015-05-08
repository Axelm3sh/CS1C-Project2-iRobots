#include "Input.h"
#include "TestimonialNode.h"

TestimonialList TakeInput()
{
	ifstream testimonialInput;
	string user;
	string model;
	string text;
	TestimonialList testimonialList;

	TestimonialNode testNode;

	testimonialInput.open("Testimonials.txt");

	while(testimonialInput)
	{
		getline(testimonialInput, testNode.user);
		getline(testimonialInput, testNode.model);
		getline(testimonialInput, testNode.text);

		testimonialInput.ignore(100, '\n');

		if(testNode.user != "")
		{
			testimonialList.Add(testNode);
		}
	}

	testimonialInput.close();
	testimonialInput.clear();

	return testimonialList;
}
